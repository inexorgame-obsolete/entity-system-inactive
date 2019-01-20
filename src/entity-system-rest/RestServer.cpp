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

		std::shared_ptr<EntityTypeApiEntitiesTypesResource> spEntityTypeApiEntitiesTypesResource,
		std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidResource> spEntityTypeApiEntitiesTypesEntity_type_uuidResource,
		std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidAttributesNameResource> spEntityTypeApiEntitiesTypesEntity_type_uuidAttributesNameResource,
		std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidInstancesResource> spEntityTypeApiEntitiesTypesEntity_type_uuidInstancesResource,
		std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsIncomingResource> spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsIncomingResource,
		std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsOutgoingResource> spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsOutgoingResource,
		std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsResource> spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsResource,
		std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidAttributesResource> spEntityTypeApiEntitiesTypesEntity_type_uuidAttributesResource
	)
		: EntityTypeApi(
			spEntityTypeApiEntitiesTypesResource,
			spEntityTypeApiEntitiesTypesEntity_type_uuidResource,
			spEntityTypeApiEntitiesTypesEntity_type_uuidAttributesNameResource,
			spEntityTypeApiEntitiesTypesEntity_type_uuidInstancesResource,
			spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsIncomingResource,
			spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsOutgoingResource,
			spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsResource,
			spEntityTypeApiEntitiesTypesEntity_type_uuidAttributesResource
		)
	{
		this->log_manager = log_manager;
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
		log_manager->register_logger(LOGGER_ENTITY_REST);
//		EntitySystemApi::createResources(this->service);
		EntityTypeApi::createResources(this->service);
//		RelationshipTypeApi::createResources(this->service);
//		EntityInstanceApi::createResources(this->service);
//		RelationshipInstanceApi::createResources(this->service);
//		AttributeApi::createResources(this->entity_system, this->service);
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
