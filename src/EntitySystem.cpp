// Inexor entity system prototype
// (c)2018 Inexor

#include "EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	EntitySystem::EntitySystem()
	{
		// TODO: Implement!
	}

	
	EntitySystem::~EntitySystem()
	{
		// TODO: Implement!
	}


	// Create one single instance of the entity system.
	// Please note that the entity system is not a singleton class at the moment.
	std::shared_ptr<EntitySystem> entsys = std::make_shared<EntitySystem>();
	

};
};
