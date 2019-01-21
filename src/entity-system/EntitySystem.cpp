// Inexor entity system
// (c)2018-2019 Inexor

#include "EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	EntitySystem::EntitySystem(
		std::shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager,
		std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager,
		std::shared_ptr<inexor::entity_system::EntityAttributeTypeManager> entity_attribute_type_manager,
		std::shared_ptr<inexor::entity_system::EntityAttributeInstanceManager> entity_attribute_instance_manager,
		std::shared_ptr<inexor::entity_system::RelationTypeManager> entity_relation_type_manager,
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> entity_relation_instance_manager,
		std::shared_ptr<inexor::entity_system::RelationAttributeTypeManager> entity_relation_attribute_type_manager,
		std::shared_ptr<inexor::entity_system::RelationAttributeInstanceManager> entity_relation_attribute_instance_manager
	)
		: EntityManager(
			entity_type_manager,
			entity_instance_manager,
			entity_attribute_type_manager,
			entity_attribute_instance_manager,
			entity_relation_type_manager,
			entity_relation_instance_manager,
			entity_relation_attribute_type_manager,
			entity_relation_attribute_instance_manager
		)
	{
		// TODO: Implement!
	}

	
	EntitySystem::~EntitySystem()
	{
		// Reset entity system at shutdown.
		reset_entity_system();
	}
	

};
};
