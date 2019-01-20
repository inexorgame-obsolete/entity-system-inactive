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
		std::shared_ptr<inexor::entity_system::RestServer> rest_server,
		std::shared_ptr<inexor::logging::LogManager> log_manager
	)
	{
		this->entity_system = entity_system;
		this->rest_server = rest_server;
		this->log_manager = log_manager;
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

		// Logging initialization
		log_manager->init();
		log_manager->register_logger(LOGGER_NAME);

		spdlog::get(LOGGER_NAME)->info("init()");

#ifdef _WIN32
		spdlog::get(LOGGER_NAME)->info("PID: {}", _getpid());
#else
		spdlog::get(LOGGER_NAME)->info("PID: {}", getpid());
#endif

	}

	void InexorApplication::start()
	{
		spdlog::get(LOGGER_NAME)->info("start()");
		if (!running) {

			// Create one single instance of the entity system.
			// @note The entity system has no singleton implementation for now.
			spdlog::get(LOGGER_NAME)->info("Starting entity system...");

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
			rest_server->init();
			rest_server->set_logger(std::make_shared<RestServerLogger>());
			rest_server->startService(0);
		} else {
			spdlog::get(LOGGER_NAME)->info("Already running");
		}

	}

	void InexorApplication::run()
	{
	    spdlog::get(LOGGER_NAME)->info("Waiting for services being started");
		while (!running) {
			std::this_thread::sleep_for(10ms);
		}
	    spdlog::get(LOGGER_NAME)->info("Inexor is running");
		while (running) {
			std::this_thread::sleep_for(5s);
			spdlog::get(LOGGER_NAME)->info("Uptime: {} s", rest_server->get_uptime().count());
		}
	    spdlog::get(LOGGER_NAME)->info("Inexor is no longer running");
	}

	void InexorApplication::shutdown()
	{
		if (running) {
			spdlog::get(LOGGER_NAME)->info("Shutting down Inexor...");
			running = false;
			std::this_thread::sleep_for(1s);
			rest_server->stopService();
			spdlog::get(LOGGER_NAME)->info("Shutdown completed");
		} else {
			spdlog::get(LOGGER_NAME)->info("Not running");
		}
	}

	void InexorApplication::restart()
	{
	    spdlog::get(LOGGER_NAME)->info("Restarting Inexor...");
		shutdown();
		std::this_thread::sleep_for(1s);
		std::thread start_thread(&inexor::InexorApplication::start, this);
		std::thread run_thread(&inexor::InexorApplication::run, this);
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
