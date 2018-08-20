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


	ENTSYS_RESULT EntityManager::add_attribute_type_to_entity_type(const std::shared_ptr<EntityType>& param_entity_type,
		                                                           const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type)
	{
		return link_entity_attribute_type_to_entity_type(param_entity_attribute_type, param_entity_type);
	}


	
	/*
    ENTSYS_RESULT EntityManager::create_entity_type_with_attributes(const std::string& param_new_entity_type_name, ...)
	{
		std::shared_ptr<EntityType> temp_new_entity_type = std::make_shared<EntityType>(param_new_entity_type_name);

		// TODO: This is highly experimental!
		
		va_list args;

		va_end(args);
		
		return ENTSYS_SUCCESS;
	}
	*/

};
};
