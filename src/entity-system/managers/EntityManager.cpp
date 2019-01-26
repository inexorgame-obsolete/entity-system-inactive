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
		std::shared_ptr<inexor::entity_system::RelationTypeManager> relation_type_manager,
		std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager,
		std::shared_ptr<inexor::entity_system::RelationAttributeTypeManager> relation_attribute_type_manager,
		std::shared_ptr<inexor::entity_system::RelationAttributeInstanceManager> relation_attribute_instance_manager
    )
    {
		this->entity_type_manager = entity_type_manager;
		this->entity_instance_manager = entity_instance_manager;
		this->entity_attribute_type_manager = entity_attribute_type_manager;
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
		this->relation_type_manager = relation_type_manager;
		this->relation_instance_manager = relation_instance_manager;
		this->relation_attribute_type_manager = relation_attribute_type_manager;
		this->relation_attribute_instance_manager = relation_attribute_instance_manager;
    }


    EntityManager::~EntityManager()
    {
		// TODO: Implement!
    }


    // Order of destruction:
    // <ul>
    // <li> Instances first, then types
    // <li> Attributes first, then the container which owns the attribute
    // <li> Relationships first, then entities
    // </ul>
	void EntityManager::reset_entity_system()
	{
		// Attribute instances
		relation_attribute_instance_manager->delete_all_relation_attribute_instances();
		entity_attribute_instance_manager->delete_all_entity_attribute_instances();

		// Attribute types
		relation_attribute_type_manager->delete_all_relation_attribute_types();
		entity_attribute_type_manager->delete_all_entity_attribute_types();

		// Instances
		relation_instance_manager->delete_all_relation_instances();
		entity_instance_manager->delete_all_entity_instances();

		// Types
		relation_type_manager->delete_all_relation_types();
		entity_type_manager->delete_all_entity_types();

		// TODO: is this sufficiant?
		// TODO: add more methods here..
	}


};
};
