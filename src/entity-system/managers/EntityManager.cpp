// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityManager.hpp"


namespace inexor {
namespace entity_system {


    EntityManager::EntityManager()
    {
		// TODO: Implement!
    }


    EntityManager::~EntityManager()
    {
		// TODO: Implement!
    }

	
	void EntityManager::wire(std::shared_ptr<EntityManager> entity_manager)
	{
		EntityInstanceManager::entity_attribute_instance_manager = entity_manager;
		EntityRelationInstanceManager::entity_relation_attribute_instance_manager = entity_manager;
	}


	void EntityManager::reset_entity_system()
	{
		// Delete instances before deleting types!
		delete_all_entity_attribute_instances();
		delete_all_entity_instances();
		delete_all_entity_attribute_types();
		delete_all_entity_types();

		// TODO: add more methods here..
	}


};
};
