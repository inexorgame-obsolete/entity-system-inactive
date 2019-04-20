#include "InexorApplication.hpp"

#include "spdlog/spdlog.h"

namespace inexor {

	// Static instances of the Inexor application(s)
	std::vector<InexorApplication *> InexorApplication::instances;

	InexorApplication::InexorApplication(
		EntitySystemModulePtr entity_system_module,
		TypeSystemModulePtr type_system_module,
		ConfigurationModulePtr configuration_module,
		RestServerPtr rest_server,
		EntitySystemDebuggerPtr entity_system_debugger,
		VisualScriptingSystemModulePtr visual_scripting_system_module,
		CommandModulePtr command_module,
		ClientModulePtr client_module,
		LogManagerPtr log_manager
	)
	{
		this->entity_system_module = entity_system_module;
		this->type_system_module = type_system_module;
		this->configuration_module = configuration_module;
		this->rest_server = rest_server;
		this->entity_system_debugger = entity_system_debugger;
		this->visual_scripting_system_module = visual_scripting_system_module;
		this->command_module = command_module;
		this->client_module = client_module;
		this->log_manager = log_manager;
		this->running = false;
	}
	
	InexorApplication::~InexorApplication()
	{
        // shutdown();
	}

	void InexorApplication::pre_init(int argc, char* argv[])
	{
		// Register application instance in static vector
		// You can't do this in the constructor
		InexorApplication::instances.push_back(this);

		// Debugger
		// TODO: enable with macro
		entity_system_debugger->init();

		// Logging initialization
		log_manager->init();
		log_manager->register_logger(LOGGER_NAME);
		entity_system_debugger->init_logger();

		spdlog::get(LOGGER_NAME)->info("init()");

#ifdef _WIN32
		spdlog::get(LOGGER_NAME)->info("PID: {}", _getpid());
#else
		spdlog::get(LOGGER_NAME)->info("PID: {}", getpid());
#endif

		// Type system initialization.
		type_system_module->init();

		// Configuration manager initialization.
		configuration_module->init(argc, argv);

		// Initialize the REST server
		rest_server->set_service(rest_server);
		rest_server->set_signal_handler(SIGINT, InexorApplication::call_sighup_handlers);
		rest_server->set_signal_handler(SIGTERM, InexorApplication::call_sigterm_handlers);
		// rest_server->init();
		rest_server->set_logger(std::make_shared<RestServerLogger>());
	}

	void InexorApplication::init()
	{
	    spdlog::get(LOGGER_NAME)->info("Starting Inexor...");

		// Initialize the visual scripting.
		visual_scripting_system_module->init();

        // Initialize the command module
		command_module->init();

		// Initialize the rendering.
		client_module->init();
	}

	void InexorApplication::run()
	{
		// Start the REST server and just go an as soon as it is started.
		rest_server->init();

		rest_server->wait_for_being_ready();

		running = true;

	    spdlog::get(LOGGER_NAME)->info("Inexor is running");
		while(running && !client_module->is_restart_requested())
        {
			// everything else happens in the execution graph or in threads for the ES instances.

			// main thread = poll events
			std::this_thread::sleep_for(10ms);

			// Main thread update
			client_module->update();

			// Shutdown requested?
			if (client_module->is_shutdown_requested())
			{
				shutdown();
			}

        }

		// Restart requested?
		if (client_module->is_restart_requested())
		{
			restart();
		}

	}

	void InexorApplication::shutdown()
	{
		if(!running)
        {
			spdlog::get(LOGGER_NAME)->info("Not running");
			return;
		}

		spdlog::get(LOGGER_NAME)->info("Shutting down Inexor...");

        // TODO: Why do we need this?
		// std::this_thread::sleep_for(1s);

        // Shutdown REST server.
		rest_server->shutdown();

		// Shut down the client module.
		client_module->shutdown();

		// Shut down the visual scripting module.
		visual_scripting_system_module->shutdown();

		running = false;
		spdlog::get(LOGGER_NAME)->info("Shutdown completed");
	}

	void InexorApplication::restart()
	{
	    spdlog::get(LOGGER_NAME)->info("Restarting Inexor...");
		shutdown();
		init();
		run();
	    spdlog::get(LOGGER_NAME)->info("Restart completed");
	}

//	void InexorApplication::register_logger(std::string logger_name)
//    {
//		log_manager->register_logger(logger_name);
//	}
//
//	EntitySystemModulePtr InexorApplication::get_entity_system()
//	{
//		return entity_system_module;
//	}
//
//
//	RestServerPtr InexorApplication::get_rest_server()
//	{
//		return rest_server;
//	}

	void InexorApplication::sighup_handler(const int signal_number)
	{
	    spdlog::get(LOGGER_NAME)->info("Received SIGINT signal number {}", signal_number);
	    restart();
	}

	void InexorApplication::sigterm_handler(const int signal_number)
	{
	    spdlog::get(LOGGER_NAME)->info("Received SIGTERM signal number {}", signal_number);
		shutdown();
	}

}
