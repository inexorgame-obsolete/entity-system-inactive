#include "EntitySystem.hpp"

namespace inexor {
namespace entity_system {

	EntitySystem::EntitySystem(
		EntityManagerPtr entity_manager,
		RelationManagerPtr relation_manager,
		BuilderFactoryManagerPtr builder_factory_manager
	)
		: entity_manager(entity_manager),
		  relation_manager(relation_manager),
		  builder_factory_manager(builder_factory_manager)
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

}
}
