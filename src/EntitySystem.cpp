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
		/// Reset entity system at shutdown.
		reset_entity_system();
	}


	// Create one single instance of the entity system.
	// @note The entity system has no singleton implementation for now.
	std::shared_ptr<EntitySystem> entsys = std::make_shared<EntitySystem>();
	

};
};
