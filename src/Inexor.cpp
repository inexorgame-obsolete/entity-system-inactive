// Inexor
// (c)2018-2019 Inexor

#include "Inexor.hpp"

using namespace inexor::entity_system;

namespace inexor {

	std::shared_ptr<RestServer> _rest_server;
	int _rest_server_port;


	void sighup_handler(const int signal_number)
	{
		std::cout << "Received SIGINT signal number " << signal_number << std::endl;
		std::cout << "Stopping REST server on port " << _rest_server_port << std::endl;
		_rest_server->stopService();
	}

	void sigterm_handler(const int signal_number)
	{
		std::cout << "Received SIGTERM signal number " << signal_number << std::endl;
		std::cout << "Stopping REST server on port " << _rest_server_port << std::endl;
		_rest_server->stopService();
	}

	void ready_handler(Service&)
	{
		std::cout << "REST server on port " << _rest_server_port << " is ready." << std::endl;
#ifdef _WIN32
		std::cout << "PID: " << _getpid() << std::endl;
#else
		std::cout << "PID: " << getpid() << std::endl;
#endif
	}

	Inexor::Inexor()
	{
		std::cout << "Inexor (c) 2009-2019" << std::endl;

		// Create one single instance of the entity system.
		// @note The entity system has no singleton implementation for now.
		std::cout << "Starting entity system" << std::endl;
		entity_system = std::make_shared<inexor::entity_system::EntitySystem>();
		entity_system->wire(entity_system);

		// Create a simple subsystem which uses the entity system
		auto color_manager = std::make_shared<inexor::entity_system::example::ColorManager>(entity_system);

		// We populate the entity system with an entity type with three attributes and create an instance
		std::cout << "Populating entity system with an entity type with three attributes and create an instance" << std::endl;
		/*
        auto entity_type_camera = entity_system->create_entity_type("CAMERA");
		auto attribute_type_position_x = entity_system->create_entity_attribute_type("position_x", ENTSYS_DATA_TYPE_FLOAT);
		auto attribute_type_position_y = entity_system->create_entity_attribute_type("position_y", ENTSYS_DATA_TYPE_FLOAT);
		auto attribute_type_position_z = entity_system->create_entity_attribute_type("position_z", ENTSYS_DATA_TYPE_FLOAT);
		entity_type_camera->link_attribute_type(attribute_type_position_x);
		entity_type_camera->link_attribute_type(attribute_type_position_y);
		entity_type_camera->link_attribute_type(attribute_type_position_z);
		auto entity_instance_camera_1 = entity_system->create_entity_instance(entity_type_camera);
        */

	    // Setup REST server
	    _rest_server_port = rest_server_port;
		std::cout << "Starting REST server on port " << rest_server_port << std::endl;
	    rest_server = std::make_shared<RestServer>(entity_system);
	    rest_server->set_service(rest_server);
	    rest_server->set_ready_handler(ready_handler);
	    rest_server->set_signal_handler(SIGINT, sighup_handler);
	    rest_server->set_signal_handler(SIGTERM, sigterm_handler);
	    rest_server->create_resources();
	    rest_server->startService(rest_server_port);
	    _rest_server = rest_server;
	}

	
	Inexor::~Inexor()
	{
		_rest_server->stopService();
	}


};
