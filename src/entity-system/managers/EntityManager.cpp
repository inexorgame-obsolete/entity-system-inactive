#include "EntityManager.hpp"

namespace inexor {
namespace entity_system {

	EntityManager::EntityManager(
		std::shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager,
		std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager,
		std::shared_ptr<inexor::entity_system::EntityAttributeTypeManager> entity_attribute_type_manager,
		std::shared_ptr<inexor::entity_system::EntityAttributeInstanceManager> entity_attribute_instance_manager
	)
	{
		this->entity_type_manager = entity_type_manager;
		this->entity_instance_manager = entity_instance_manager;
		this->entity_attribute_type_manager = entity_attribute_type_manager;
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
	}

	EntityManager::~EntityManager()
	{
	}

	// Order of destruction:
	// <ul>
	// <li> Attributes first, then the container which owns the attribute
	// <li> Instances first, then types
	// </ul>
	void EntityManager::reset_entity_system()
	{
		// Attribute instances
		entity_attribute_instance_manager->delete_all_entity_attribute_instances();

		// Attribute types
		entity_attribute_type_manager->delete_all_entity_attribute_types();

		// Instances
		entity_instance_manager->delete_all_entity_instances();

		// Types
		entity_type_manager->delete_all_entity_types();
	}

};
};
