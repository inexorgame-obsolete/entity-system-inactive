// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityManager.hpp"


namespace inexor {
namespace entity_system {


    EntityManager::EntityManager(
		std::shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager,
		std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager,
		std::shared_ptr<inexor::entity_system::EntityAttributeTypeManager> entity_attribute_type_manager,
		std::shared_ptr<inexor::entity_system::EntityAttributeInstanceManager> entity_attribute_instance_manager,
		std::shared_ptr<inexor::entity_system::EntityRelationTypeManager> entity_relation_type_manager,
		std::shared_ptr<inexor::entity_system::EntityRelationInstanceManager> entity_relation_instance_manager,
		std::shared_ptr<inexor::entity_system::EntityRelationAttributeTypeManager> entity_relation_attribute_type_manager,
		std::shared_ptr<inexor::entity_system::EntityRelationAttributeInstanceManager> entity_relation_attribute_instance_manager
    )
    {
		this->entity_type_manager = entity_type_manager;
		this->entity_instance_manager = entity_instance_manager;
		this->entity_attribute_type_manager = entity_attribute_type_manager;
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
		this->entity_relation_type_manager = entity_relation_type_manager;
		this->entity_relation_instance_manager = entity_relation_instance_manager;
		this->entity_relation_attribute_type_manager = entity_relation_attribute_type_manager;
		this->entity_relation_attribute_instance_manager = entity_relation_attribute_instance_manager;
    }


    EntityManager::~EntityManager()
    {
		// TODO: Implement!
    }


	void EntityManager::reset_entity_system()
	{
		// Delete instances before deleting types!
		entity_attribute_instance_manager->delete_all_entity_attribute_instances();
		entity_instance_manager->delete_all_entity_instances();
		entity_attribute_type_manager->delete_all_entity_attribute_types();
		entity_type_manager->delete_all_entity_types();

		// TODO: add more methods here..
	}


};
};
