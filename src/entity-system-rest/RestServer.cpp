// Inexor entity system
// (c)2018 Inexor

#include "RestServer.hpp"

using namespace std;
using namespace restbed;
using namespace inexor::entity_system::rest::api;

namespace inexor {
namespace entity_system {


	RestServer::RestServer(std::shared_ptr<inexor::entity_system::EntitySystem> entity_system)
	{
		this->entity_system = entity_system;
	}


	RestServer::~RestServer()
	{
		// this->stop();
	}

	std::shared_ptr<Service> RestServer::get_service()
	{
		return this->service;
	}

	void RestServer::set_service(std::shared_ptr<Service> service)
	{
		this->service = service;
	}

	void RestServer::create_resources()
	{
//		EntitySystemApi::createResources(this->entity_system, this->service);
		EntityTypeApi::createResources(this->entity_system, this->service);
//		RelationshipTypeApi::createResources(this->entity_system, this->service);
//		EntityInstanceApi::createResources(this->entity_system, this->service);
//		RelationshipInstanceApi::createResources(this->entity_system, this->service);
//		AttributeApi::createResources(this->entity_system, this->service);
	}

	std::shared_ptr<inexor::entity_system::EntitySystem> RestServer::get_entity_system()
	{
		return this->entity_system;
	}

	void RestServer::startService(int const& port) {
		shared_ptr<Settings> settings = make_shared<Settings>();
		settings->set_port(port);
		settings->set_root("/api/v1");
		settings->set_worker_limit(8);
		settings->set_default_header("Connection", "close");
		this->service->start(settings);
	}

	void RestServer::stopService() {
		this->service->stop();
	}

};
};
