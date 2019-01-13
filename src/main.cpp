// Inexor entity system prototype
// (c)2018-2019 Inexor

#include <memory>
#include <cstdlib>
#include <restbed>
#include <csignal>
#include <sys/types.h>

#ifdef _WIN32
    #include <process.h>
#else
    #include <unistd.h>
#endif

#include "entity-system/EntitySystem.hpp"
#include "entity-system-rest/RestServer.hpp"

namespace inexor {
namespace entity_system {

	std::shared_ptr<inexor::entity_system::EntitySystem> entity_system;

	std::shared_ptr<RestServer> rest_server;

	int rest_server_port = 8080;

}
}

using namespace inexor::entity_system;

void sighup_handler( const int signal_number )
{
	std::cout << "Received SIGINT signal number " << signal_number << std::endl << "Stopping REST server on port " << rest_server_port << std::endl;
	rest_server->stopService();
}

void sigterm_handler( const int signal_number )
{
	std::cout << "Received SIGTERM signal number " << signal_number << std::endl << "Stopping REST server on port " << rest_server_port << std::endl;
	rest_server->stopService();
}

void ready_handler( Service& )
{
#ifdef _WIN32
	std::cout << "REST server on port " << rest_server_port << " is ready (PID: " << _getpid() << ")" << std::endl;
#else
	std::cout << "REST server on port " << rest_server_port << " is ready (PID: " << getpid() << ")" << std::endl;
#endif
}

int main(int argc, char* argv[])
{
	std::cout << "Inexor Entity System (c) 2018-2019" << std::endl;

	// Create one single instance of the entity system.
	// @note The entity system has no singleton implementation for now.
	entity_system = std::make_shared<inexor::entity_system::EntitySystem>();

	// We populate the entity system with an entity type with three attributes and create an instance
	auto entity_type_camera = entity_system->create_entity_type("CAMERA");
	auto attribute_type_position_x = entity_system->create_entity_attribute_type("position_x", ENTSYS_DATA_TYPE_FLOAT);
	auto attribute_type_position_y = entity_system->create_entity_attribute_type("position_y", ENTSYS_DATA_TYPE_FLOAT);
	auto attribute_type_position_z = entity_system->create_entity_attribute_type("position_z", ENTSYS_DATA_TYPE_FLOAT);
	entity_type_camera->link_attribute_type(attribute_type_position_x);
	entity_type_camera->link_attribute_type(attribute_type_position_y);
	entity_type_camera->link_attribute_type(attribute_type_position_z);
	auto entity_instance_camera_1 = entity_system->create_entity_instance(entity_type_camera);

    // Setup REST server
	std::cout << "Starting REST server on port " << rest_server_port << std::endl;
    rest_server = std::make_shared<RestServer>(entity_system);
    rest_server->set_service(rest_server);
    rest_server->set_ready_handler(ready_handler);
    rest_server->set_signal_handler(SIGINT, sighup_handler);
    rest_server->set_signal_handler(SIGTERM, sigterm_handler);
    rest_server->create_resources();
    rest_server->startService(rest_server_port);
	std::cout << "Exit" << std::endl;
    return EXIT_SUCCESS;

}
