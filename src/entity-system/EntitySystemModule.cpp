#include "EntitySystemModule.hpp"

namespace inexor {
namespace entity_system {

	EntitySystemModule::EntitySystemModule(
		EntityManagerPtr entity_manager,
		RelationManagerPtr relation_manager,
		BuilderFactoryManagerPtr builder_factory_manager
	)
		: entity_manager(entity_manager),
		  relation_manager(relation_manager),
		  builder_factory_manager(builder_factory_manager)
	{
	}

	EntitySystemModule::~EntitySystemModule()
	{
	}

    // Order of destruction:
    // <ul>
    // <li> Relations
	// <li> Entities
    // </ul>
	void EntitySystemModule::reset_entity_system()
	{
		// Reset relations
		relation_manager->reset_entity_system();

		// Reset entities
		entity_manager->reset_entity_system();
	}

}
}
