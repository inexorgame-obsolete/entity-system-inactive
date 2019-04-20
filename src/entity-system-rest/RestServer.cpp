#include "RestServer.hpp"

using namespace std;
using namespace restbed;
using namespace inexor::entity_system::rest::api;

namespace inexor {
namespace entity_system {

	RestServer::RestServer(
		std::shared_ptr<inexor::logging::LogManager> log_manager,
		std::shared_ptr<EntityTypeApi> entity_type_api,
		std::shared_ptr<RelationTypeApi> relation_type_api,
		std::shared_ptr<EntityInstanceApi> entity_instance_api,
		std::shared_ptr<RelationInstanceApi> relation_instance_api,
		std::shared_ptr<AttributeApi> attribute_api
	): service_thread()
	{
		this->log_manager = log_manager;

		// Inject the REST APIs
		this->entity_type_api = entity_type_api;
		this->relation_type_api = relation_type_api;
		this->entity_instance_api = entity_instance_api;
		this->relation_instance_api = relation_instance_api;
		this->attribute_api = attribute_api;
		this->port = 8080;
		this->root = "api/v1";
		this->running = false;
	}

	RestServer::~RestServer()
	{
		if(service_thread.joinable())
        {
            service_thread.join();
        }
	}

	ServicePtr RestServer::get_service()
	{
		return this->service;
	}

	void RestServer::set_service(ServicePtr service)
	{
		this->service = service;
	}

	void RestServer::init()
	{
		// Register logger
		log_manager->register_logger(LOGGER_NAME);

		// Publish resources on the service
		entity_type_api->publish_resources(this->service);
		relation_type_api->publish_resources(this->service);
		entity_instance_api->publish_resources(this->service);
		relation_instance_api->publish_resources(this->service);
		attribute_api->publish_resources(this->service);
		// entity_system_api::publish_resources(this->service);

    	// We have to create new settings every time we start the server!
    	this->settings = this->create_settings();

    	this->set_ready_handler(std::bind(&RestServer::http_ready_handler, this, std::placeholders::_1));

        service_thread = std::thread([this]() {
			// This is blocking for ever, so start it in own thread.
			this->service->start(this->settings);
			spdlog::get(LOGGER_NAME)->debug("REST server thread finished");
		});
        service_thread.detach();

        // port is ignored (already set in the settings!)
	    spdlog::get(LOGGER_NAME)->debug("Starting REST server on http://localhost:{}/{}", settings->get_port(), settings->get_root());
	}

	void RestServer::shutdown()
	{
		spdlog::get(LOGGER_NAME)->info("Stopping REST server on http://localhost:{}/{}", settings->get_port(), settings->get_root());
		service->stop();
		port++;
		spdlog::get(LOGGER_NAME)->info("REST server stopped");

		// Suppress resources on the service
		// entity_system_api::suppress_resources(this->service);
		attribute_api->suppress_resources(this->service);
		relation_instance_api->suppress_resources(this->service);
		entity_instance_api->suppress_resources(this->service);
		relation_type_api->suppress_resources(this->service);
		entity_type_api->suppress_resources(this->service);

		running = false;
	}

	SettingsPtr RestServer::create_settings()
	{
		// TODO: make this more dynamic!
		std::shared_ptr<Settings> settings = std::make_shared<Settings>();
		settings->set_port(this->port);
		settings->set_bind_address("");
		settings->set_root(this->root);
		settings->set_worker_limit(1);
		// settings->set_worker_limit(std::thread::hardware_concurrency());
		settings->set_default_header("Connection", "close");
		return settings;
	}

	SettingsPtr RestServer::get_settings()
	{
		return settings;
	}

	void RestServer::http_ready_handler(restbed::Service& service)
	{
	    spdlog::get(LOGGER_NAME)->info("REST server is running on http://localhost:{}/{}", settings->get_port(), settings->get_root());
		running = true;
	}

	void RestServer::wait_for_being_ready()
	{
	    spdlog::get(LOGGER_NAME)->info("Waiting for REST server being started");
	    std::chrono::steady_clock::time_point timeout = std::chrono::steady_clock::now() + std::chrono::seconds(2);
		while (!running && std::chrono::steady_clock::now() < timeout)
        {
			// wait until the rest server started up
			// which calls ready_handlers() as soon as it is.
			// Then running becomes true and we leave
			std::this_thread::sleep_for(10ms);
		}
		if (running)
		{
		    spdlog::get(LOGGER_NAME)->info("REST server is up and ready.");
		} else {
			spdlog::get(LOGGER_NAME)->error("REST server didn't came up? [TODO: The ready_handler is not working after a restart]");
		}
	}

}
}
