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

	
	void EntityManager::reset_entity_system()
	{
		delete_all_entity_types_and_entity_type_instances();
		// TODO: add more methods here..
	}


	ENTSYS_RESULT EntityManager::create_entity_type_with_attributes(const std::shared_ptr<EntityType>& param_new_entity_type,
				                                                    const std::vector<std::shared_ptr<EntityAttributeType>>& param_entity_attribute_types)
	{
		// Validate all entity attribute types before adding them
		if(ENTSYS_DATA_VALID == validate_attribute_types(param_entity_attribute_types))
		{
			for(std::size_t i=0; i<param_entity_attribute_types.size(); i++)
			{
				// TODO: Should we create entity attribute types if they have not been created yet here?
				//create_entity_attribute_type(param_entity_attribute_types[i]);

				param_new_entity_type->link_attribute_type(param_entity_attribute_types[i]);
			}

			create_entity_type(param_new_entity_type);
		}

		return ENTSYS_ERROR_DATA_INVALID;
	}


};
};
