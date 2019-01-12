// Inexor entity system prototype
// (c)2018 Inexor

#include "RestServer.hpp"

using namespace std;
using namespace restbed;
using namespace inexor::entity_system::rest::api;

namespace inexor {
namespace entity_system {


	RestServer::RestServer()
	{
		entity_system_api = make_shared<EntitySystemApi>();
		entity_type_api = make_shared<EntityTypeApi>();
		relationship_type_api = make_shared<RelationshipTypeApi>();
		entity_instance_api = make_shared<EntityInstanceApi>();
		relationship_instance_api = make_shared<RelationshipInstanceApi>();
		attribute_api = make_shared<AttributeApi>();
	}


	RestServer::~RestServer()
	{
		// this->stop();
	}

	void RestServer::start_services()
	{
		std::cout << "Starting Inexor Entity System REST server on port 8080" << std::endl;
		entity_system_api->startService(8080);
		attribute_api->startService(8080);
    }

	void RestServer::stop_services()
	{
		entity_system_api->stopService();
		attribute_api->stopService();
	}

};
};
