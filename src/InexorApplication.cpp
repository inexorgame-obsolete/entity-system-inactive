// Inexor
// (c)2018-2019 Inexor

#include "spdlog/spdlog.h"
#include "InexorApplication.hpp"
#include <GLFW/glfw3.h>


using namespace inexor::entity_system;
using namespace spdlog;

namespace inexor {

	// Static instances of the Inexor application(s)
	std::vector<InexorApplication *> InexorApplication::instances;

	InexorApplication::InexorApplication(
		std::shared_ptr<inexor::entity_system::EntitySystem> entity_system,
		std::shared_ptr<inexor::entity_system::type_system::TypeSystemManager> type_system_manager,
		std::shared_ptr<inexor::configuration::ConfigurationManager> configuration_manager,
		std::shared_ptr<inexor::entity_system::RestServer> rest_server,
		std::shared_ptr<inexor::entity_system::EntitySystemDebugger> entity_system_debugger,
		std::shared_ptr<inexor::visual_scripting::VisualScriptingSystem> visual_scripting_system,
		std::shared_ptr<inexor::logging::LogManager> log_manager,
		std::shared_ptr<inexor::renderer::RendererManager> renderer_manager
	)
	{
		this->entity_system = entity_system;
		this->type_system_manager = type_system_manager;
		this->configuration_manager = configuration_manager;
		this->rest_server = rest_server;
		this->entity_system_debugger = entity_system_debugger;
		this->visual_scripting_system = visual_scripting_system;
		this->log_manager = log_manager;
		this->renderer_manager = renderer_manager;
		this->running = false;
	}
	
	InexorApplication::~InexorApplication()
	{
		// shutdown();
	}

	void InexorApplication::init()
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

		spdlog::get(LOGGER_NAME)->info("init()");

#ifdef _WIN32
		spdlog::get(LOGGER_NAME)->info("PID: {}", _getpid());
#else
		spdlog::get(LOGGER_NAME)->info("PID: {}", getpid());
#endif

		// Type system initialization
		type_system_manager->init();

		// Configuration manager initialization
		configuration_manager->init();

		// Initialize the visual scripting
		visual_scripting_system->init();

		// Initialize the rendering
		renderer_manager->init();

		// Setup REST server
		rest_server->set_service(rest_server);
		rest_server->set_signal_handler(SIGINT, InexorApplication::call_sighup_handlers);
		rest_server->set_signal_handler(SIGTERM, InexorApplication::call_sigterm_handlers);
		rest_server->set_ready_handler(InexorApplication::call_ready_handlers);
		rest_server->init();
		rest_server->set_logger(std::make_shared<RestServerLogger>());
	}

	void InexorApplication::run()
	{
		// Start the REST server and just go an as soon as it is started.
		rest_server->startService();

	    spdlog::get(LOGGER_NAME)->info("Waiting for REST service being started");
		while (!running) {
			// wait until the rest server started up
			// which calls ready_handlers() as soon as it is.
			// Then running becomes true and we leave
			std::this_thread::sleep_for(10ms);
		}

	    spdlog::get(LOGGER_NAME)->info("Inexor is running");
		while (running) {
			// everything else happens in the execution graph or in threads for the ES instances.
			std::this_thread::sleep_for(5s);
			spdlog::get(LOGGER_NAME)->info("Uptime: {} s", rest_server->get_uptime().count());
			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	void InexorApplication::shutdown()
	{
		if (running) {
			spdlog::get(LOGGER_NAME)->info("Not running");
			return;
		}

		spdlog::get(LOGGER_NAME)->info("Shutting down Inexor...");
		std::this_thread::sleep_for(1s);
		rest_server->stopService();
		running = false;
		spdlog::get(LOGGER_NAME)->info("Shutdown completed");
	}

	void InexorApplication::restart()
	{
	    spdlog::get(LOGGER_NAME)->info("Restarting Inexor...");
		shutdown();
		run();
	    spdlog::get(LOGGER_NAME)->info("Restart completed");
	}

	void InexorApplication::register_logger(std::string logger_name) {
		log_manager->register_logger(logger_name);
	}

	std::shared_ptr<inexor::entity_system::EntitySystem> InexorApplication::get_entity_system()
	{
		return entity_system;
	}


	std::shared_ptr<inexor::entity_system::RestServer> InexorApplication::get_rest_server()
	{
		return rest_server;
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

	void InexorApplication::ready_handler(Service&)
	{
	    spdlog::get(LOGGER_NAME)->info("REST server is running on http://localhost:{}/{}", rest_server->get_settings()->get_port(), rest_server->get_settings()->get_root());

		// Set running state
		running = true;

	}

};
