// Inexor entity system prototype
// (c)2018-2019 Inexor

#ifdef __linux__
#include <vector>
#include <signal.h>
#include <unistd.h>
#endif

#include "EntitySystem.hpp"
#include "rest/RestServer.hpp"

namespace inexor {
namespace entity_system {

	std::shared_ptr<inexor::entity_system::EntitySystem> entity_system;

	std::shared_ptr<RestServer> rest_server;

}
}

using namespace inexor::entity_system;

#ifdef __linux__
static void sigHandler(int sig){
    switch(sig){
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
        case SIGHUP:
        default:
        	// rest_server->stop_services();
        	rest_server->stopService();
            break;
    }
    exit(0);
}

static void setUpUnixSignals(std::vector<int> quitSignals) {
    sigset_t blocking_mask;
    sigemptyset(&blocking_mask);
    for (auto sig : quitSignals)
        sigaddset(&blocking_mask, sig);

    struct sigaction sa;
    sa.sa_handler = sigHandler;
    sa.sa_mask    = blocking_mask;
    sa.sa_flags   = 0;

    for (auto sig : quitSignals)
        sigaction(sig, &sa, nullptr);
}
#endif

int main(int argc, char* argv[])
{
	std::cout << "Inexor Entity System (c) 2018-2019" << std::endl;

	// Setup signal handling
#ifdef __linux__
    std::vector<int> sigs{SIGQUIT, SIGINT, SIGTERM, SIGHUP};
    setUpUnixSignals(sigs);
#endif

	// Create one single instance of the entity system.
	// @note The entity system has no singleton implementation for now.
	entity_system = std::make_shared<inexor::entity_system::EntitySystem>();

	auto entity_type_camera = entity_system->create_entity_type("CAMERA");
	auto attribute_type_position_x = entity_system->create_entity_attribute_type("position_x", ENTSYS_DATA_TYPE_FLOAT);
	auto attribute_type_position_y = entity_system->create_entity_attribute_type("position_y", ENTSYS_DATA_TYPE_FLOAT);
	auto attribute_type_position_z = entity_system->create_entity_attribute_type("position_z", ENTSYS_DATA_TYPE_FLOAT);
	entity_type_camera->link_attribute_type(attribute_type_position_x);
	entity_type_camera->link_attribute_type(attribute_type_position_y);
	entity_type_camera->link_attribute_type(attribute_type_position_z);

//	auto attribute_type_position_x_1 = entity_system->create_entity_attribute_type_instance(attribute_type_position_x);
//	auto attribute_type_position_y_1 = entity_system->create_entity_attribute_type_instance(attribute_type_position_y);
//	auto attribute_type_position_z_1 = entity_system->create_entity_attribute_type_instance(attribute_type_position_z);

	auto entity_instance_camera_1 = entity_system->create_entity_instance(entity_type_camera);
//	entity_instance_camera_1->add_entity_attribute_instance(attribute_type_position_x, attribute_type_position_x_1);
//	entity_instance_camera_1->add_entity_attribute_instance(attribute_type_position_y, attribute_type_position_y_1);
//	entity_instance_camera_1->add_entity_attribute_instance(attribute_type_position_z, attribute_type_position_z_1);

    // Setup REST server
	std::cout << "Starting REST server" << std::endl;
    rest_server = std::make_shared<RestServer>(entity_system);
    rest_server->set_service(rest_server);
    rest_server->create_resources();
    rest_server->startService(8080);
    return 0;

}
