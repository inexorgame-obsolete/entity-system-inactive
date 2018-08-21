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

	
	ENTSYS_RESULT EntityManager::create_entity_type_with_attributes(const std::shared_ptr<EntityType>& param_new_entity_type,
				                                                    const std::vector<std::shared_ptr<EntityAttributeType>>& param_vector_of_entity_attribute_types)
	{
		// TODO: Implement a data validation method for a vector of EntityAttributeType!



		// New entity types can have linked entity attribute types.
		// Only if the data of the new entity type AND the data of
		// all linked entity attribute types are valid the new entity 
		// type will be added to the entity system!
		if(ENTSYS_DATA_VALID == param_new_entity_type->validate())
		{
			// Loop through all linked entity attribut types and validate their data.
			for(std::size_t i=0; i<param_vector_of_entity_attribute_types.size(); i++)
			{			
				if(ENTSYS_DATA_VALID == param_vector_of_entity_attribute_types[i]->validate())
				{
					// This entity attribute type is valid.
					param_new_entity_type->link_entity_attribute_type_to_entity_type(param_vector_of_entity_attribute_types[i]);
				}
				else
				{
					// At least one attribute type is invalid
					// Please note that we can not print the name of the entity attribute type
					// whose data is invalid because maybe its name has not been set.
					// (This could be reason why it is invalid)
					error_message("error: data validation for new entity attribute type failed!");
					error_message("Transaction aborted. No new entity type added!");
					return ENTSYS_ERROR_DATA_INVALID;
				}
			}
			
			// New entity type and all linked attribute types are valid.
			// Add it to the entity system!
			create_entity_type(param_new_entity_type);

			return ENTSYS_SUCCESS;
		}

		error_message("error: data validation for new entity type failed!");
		return ENTSYS_ERROR_DATA_INVALID;
	}


};
};
