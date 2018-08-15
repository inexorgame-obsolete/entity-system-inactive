// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeManager.hpp"


namespace inexor {
namespace entity_system {
    

    EntityTypeManager::EntityTypeManager()
    {
		// TODO: implement!
    }


    EntityTypeManager::~EntityTypeManager()
    {
		// TODO: implement!
    }
	

	bool EntityTypeManager::does_entity_type_exist(const std::string& param_entity_type_name)
	{
		// Loop through map of entity types.
		// Returns false is entity type does not already exist.
		return ! (map_of_entity_types.end() == map_of_entity_types.find(param_entity_type_name.c_str()) );
	}

	
	ENTSYS_RESULT EntityTypeManager::create_entity_type(const std::shared_ptr<EntityType>& param_new_entity_type)
	{
		if(ENTSYS_DATA_VALID != param_new_entity_type->validate())
		{
			error_message("error: data of new entity type is invalid!");
			return ENTSYS_ERROR_DATA_INVALID;
		}
		
		// Get the name of the new entity type
		std::string new_ent_type_name = param_new_entity_type->get_entity_type_name();

		// TODO: Check if entity type with this name does already exist!
		if(false == does_entity_type_exist(new_ent_type_name))
		{
			// Add to map of entity type which are available in the entity system!
			map_of_entity_types[new_ent_type_name] = param_new_entity_type;
		}
		else
		{
			error_message("error: new entity type already exists!");
			return ENTSYS_ERROR_DATA_DUPLICATE;
		}

		return ENTSYS_SUCCESS;
	}


	std::size_t EntityTypeManager::entity_types_count() const
	{
		return map_of_entity_types.size();
	}


};
};
