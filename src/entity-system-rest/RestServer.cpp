// Inexor entity system
// (c)2018 Inexor

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
	)
	{
		this->log_manager = log_manager;

		// Inject the REST APIs
		this->entity_type_api = entity_type_api;
		this->relation_type_api = relation_type_api;
		this->entity_instance_api = entity_instance_api;
		this->relation_instance_api = relation_instance_api;
		this->attribute_api = attribute_api;

		// Initialize the settings
		// TODO: make this more dynamic!
		settings = make_shared<Settings>();
		settings->set_port(8080);
		settings->set_root("api/v1");
		settings->set_worker_limit(8);
		settings->set_default_header("Connection", "close");
	}

	RestServer::~RestServer()
	{
	}

	std::shared_ptr<Service> RestServer::get_service()
	{
		return this->service;
	}

	void RestServer::set_service(std::shared_ptr<Service> service)
	{
		this->service = service;
	}

	void RestServer::init()
	{
		// Register logger
		log_manager->register_logger(LOGGER_ENTITY_REST);
		// Publish resources on the service
		entity_type_api->publish_resources(this->service);
		relation_type_api->publish_resources(this->service);
		entity_instance_api->publish_resources(this->service);
		relation_instance_api->publish_resources(this->service);
		//EntitySystemApi::publish_resources(this->service);
		attribute_api->publish_resources(this->service);
	}

	shared_ptr<Settings> RestServer::get_settings()
	{
		return this->settings;
	}

	void RestServer::startService(int const& _port) {
		// port is ignored (already set in the settings!)
	    spdlog::get(LOGGER_ENTITY_REST)->info("Starting REST server on http://localhost:{}/{}", this->settings->get_port(), this->settings->get_root());
		this->service->start(settings);
	}

	void RestServer::stopService() {
	    spdlog::get(LOGGER_ENTITY_REST)->info("Stopping REST server on http://localhost:{}/{}", this->settings->get_port(), this->settings->get_root());
		this->service->stop();
	    spdlog::get(LOGGER_ENTITY_REST)->info("REST server stopped");
	}

}
}
