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
		VisualScriptingSystemModulePtr visual_scripting_system_module,
		ScriptingModulePtr scripting_module,
		CommandModulePtr command_module,
#ifndef INEXOR_WITHOUT_CLIENT
		ClientModulePtr client_module,
#endif
#ifndef INEXOR_WITHOUT_SERVER
		ServerModulePtr server_module,
#endif
		LogManagerPtr log_manager
	)
	{
		this->entity_system_module = entity_system_module;
		this->type_system_module = type_system_module;
		this->configuration_module = configuration_module;
		this->rest_server = rest_server;
		this->visual_scripting_system_module = visual_scripting_system_module;
		this->scripting_module = scripting_module;
		this->command_module = command_module;
#ifndef INEXOR_WITHOUT_CLIENT
		this->client_module = client_module;
#endif
#ifndef INEXOR_WITHOUT_SERVER
		this->server_module = server_module;
#endif
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

		// Pre initialize of the entity system module.
		// Logging is not yet ready.
		entity_system_module->pre_init();

		// Logging initialization
		log_manager->init();
		log_manager->register_logger(LOGGER_NAME);

		// Initialize the entity system module.
		entity_system_module->init();

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

		// Initialize the client module.
#ifndef INEXOR_WITHOUT_CLIENT
		client_module->init();
#endif

		// Initialize the server module.
#ifndef INEXOR_WITHOUT_SERVER
		server_module->init();
#endif

		// Initialize the scripting module.
		scripting_module->init();
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
#ifndef INEXOR_WITHOUT_CLIENT
			client_module->update();
#endif
#ifndef INEXOR_WITHOUT_SERVER
			server_module->update();
#endif

			// Shutdown requested?
#ifndef INEXOR_WITHOUT_CLIENT
			if (client_module->is_shutdown_requested())
			{
				shutdown();
			}
#endif
#ifndef INEXOR_WITHOUT_SERVER
			if (server_module->is_shutdown_requested())
			{
				shutdown();
			}
#endif

        }

		// Restart requested?
#ifndef INEXOR_WITHOUT_CLIENT
		if (client_module->is_restart_requested())
		{
			restart();
		}
#endif
#ifndef INEXOR_WITHOUT_SERVER
		if (server_module->is_restart_requested())
		{
			restart();
		}
#endif

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

		// Shut down the scripting module.
		scripting_module->init();

		// Shut down the client module.
#ifndef INEXOR_WITHOUT_CLIENT
		client_module->shutdown();
#endif
		// Shut down the server module.
#ifndef INEXOR_WITHOUT_SERVER
		server_module->shutdown();
#endif

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
