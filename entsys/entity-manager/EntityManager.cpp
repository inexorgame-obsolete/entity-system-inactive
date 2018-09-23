// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityManager.hpp"


namespace inexor {
namespace entity_system {


    EntityManager::EntityManager()
    {
		// TODO: implement!
    }


    EntityManager::~EntityManager()
    {
		// TODO: implement!
    }

	
	void EntityManager::reset()
	{
		delete_all_entity_types_and_entity_type_instances();
		// TODO: add more methods here..
	}


};
};
