// Inexor
// (c)2018-2019 Inexor

#include "InexorApplication.hpp"

using namespace inexor::entity_system;
using namespace spdlog;

namespace inexor {

	// Static instances of the Inexor application(s)
	std::vector<InexorApplication *> InexorApplication::instances;

	InexorApplication::InexorApplication(
		std::shared_ptr<inexor::entity_system::EntitySystem> entity_system,
		std::shared_ptr<inexor::entity_system::RestServer> rest_server
	)
	{
		this->entity_system = entity_system;
		this->rest_server = rest_server;
		InexorApplication::instances.push_back(this);
	}

	
	InexorApplication::~InexorApplication()
	{
		// shutdown();
	}

	void InexorApplication::start()
	{
		running = true;

		// Logging initialization
		// TODO: Move this to a new module (for example LogManager)
		spdlog::init_thread_pool(8192, 1);
		auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("inexor.log", 1024 * 1024 * 10, 3);
		std::vector<spdlog::sink_ptr> sinks {stdout_sink, rotating_sink};
		spdlog::register_logger(std::make_shared<spdlog::async_logger>(LOGGER_NAME, sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block));
		spdlog::register_logger(std::make_shared<spdlog::async_logger>("inexor.entity.rest", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block));
		spdlog::get(LOGGER_NAME)->info("Asynchronous logging initialized");

#ifdef _WIN32
		spdlog::get(LOGGER_NAME)->info("PID: {}", _getpid());
#else
		spdlog::get(LOGGER_NAME)->info("PID: {}", getpid());
#endif

		// Create one single instance of the entity system.
		// @note The entity system has no singleton implementation for now.
		spdlog::get(LOGGER_NAME)->info("Starting entity system...");
		entity_system->wire(entity_system);

		/*
		// We populate the entity system with an entity type with three attributes and create an instance
		spdlog::get("inexor.app")->info("Populating entity system with an entity type with three attributes and create an instance");
        auto entity_type_camera = entity_system->create_entity_type("CAMERA");
		auto attribute_type_position_x = entity_system->create_entity_attribute_type("position_x", ENTSYS_DATA_TYPE_FLOAT);
		auto attribute_type_position_y = entity_system->create_entity_attribute_type("position_y", ENTSYS_DATA_TYPE_FLOAT);
		auto attribute_type_position_z = entity_system->create_entity_attribute_type("position_z", ENTSYS_DATA_TYPE_FLOAT);
		entity_type_camera->link_attribute_type(attribute_type_position_x);
		entity_type_camera->link_attribute_type(attribute_type_position_y);
		entity_type_camera->link_attribute_type(attribute_type_position_z);
		auto entity_instance_camera_1 = entity_system->create_entity_instance(entity_type_camera);

		// Create a simple subsystem which uses the entity system
		auto color_manager = std::make_shared<inexor::entity_system::example::ColorManager>(entity_system);

        */

	    // Setup REST server
	    rest_server->set_service(rest_server);
	    rest_server->set_signal_handler(SIGINT, InexorApplication::call_sighup_handlers);
	    rest_server->set_signal_handler(SIGTERM, InexorApplication::call_sigterm_handlers);
	    rest_server->set_ready_handler(InexorApplication::call_ready_handlers);
	    rest_server->create_resources();
	    rest_server->startService(0);

	}

	void InexorApplication::run()
	{
	    spdlog::get(LOGGER_NAME)->info("Inexor is running");
		while (running) {
			std::this_thread::sleep_for(10ms);
		}
	    spdlog::get(LOGGER_NAME)->info("Inexor is no longer running");
	}

	void InexorApplication::shutdown()
	{
	    spdlog::get(LOGGER_NAME)->info("Shutting down Inexor...");
		rest_server->stopService();
	    spdlog::get(LOGGER_NAME)->info("Waiting for services to come down...");
		std::this_thread::sleep_for(1s);
		running = false;
	    spdlog::get(LOGGER_NAME)->info("Shutdown completed");
	}

	void InexorApplication::restart()
	{
	    spdlog::get(LOGGER_NAME)->info("Restarting Inexor...");
		shutdown();
		std::this_thread::sleep_for(1s);
		start();
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
		rest_server->status();
	    // spdlog::get(LOGGER_NAME)->info("REST server is running on http://localhost:{}/{}", rest_server->get_settings()->get_port(), rest_server->get_settings()->get_root());
	}

};
