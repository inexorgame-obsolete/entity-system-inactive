// Inexor entity system prototype
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

	
	void EntityManager::reset_entity_system()
	{
		// Delete instances before deleting types!
		delete_all_entity_attribute_type_instances();
		delete_all_entity_type_instances();
		delete_all_entity_attribute_types();
		delete_all_entity_types();

		// TODO: add more methods here..
	}


};
};
