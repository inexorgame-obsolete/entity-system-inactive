// Inexor entity system
// (c)2018-2019 Inexor

#include "EntitySystem.hpp"


using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace entity_system {


	EntitySystem::EntitySystem(
		shared_ptr<EntityManager> entity_manager,
		shared_ptr<RelationManager> relation_manager,
		shared_ptr<BuilderManager> builder_manager
	)
		: entity_manager(entity_manager),
		  relation_manager(relation_manager),
		  builder_manager(builder_manager)
	{
	}

	
	EntitySystem::~EntitySystem()
	{
	}


    // Order of destruction:
    // <ul>
    // <li> Relations
	// <li> Entities
    // </ul>
	void EntitySystem::reset_entity_system()
	{
		// Reset relations
		relation_manager->reset_entity_system();

		// Reset entities
		entity_manager->reset_entity_system();
	}


};
};
