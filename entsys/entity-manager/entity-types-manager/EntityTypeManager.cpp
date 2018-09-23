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
		// Returns false is entity type does not already exist.
		return !(entity_type_buffer_map.end() == entity_type_buffer_map.find(param_entity_type_name));
	}

	
	std::shared_ptr<EntityType> EntityTypeManager::create_entity_type(const std::string& param_new_entity_type)
	{
		std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(param_new_entity_type);
		// TODO: use UUID for access?
		entity_type_buffer_map[param_new_entity_type] = new_ent_type;
		return new_ent_type;

		/*
		if(ENTSYS_DATA_VALID != param_new_entity_type->validate())
		{
			error_message("error: data of new entity type is invalid!");
			return ENTSYS_ERROR_DATA_INVALID;
		}
		
		// Get the name of the new entity type.
		std::string new_ent_type_name = param_new_entity_type->get_type_name();

		// Check if entity type with this name does already exist.
		if(false == does_entity_type_exist(new_ent_type_name))
		{
			// Add to map of entity types.
			map_of_entity_types[new_ent_type_name] = param_new_entity_type;
		}
		else
		{
			error_message("error: new entity type already exists!");
			return ENTSYS_ERROR_DATA_DUPLICATE;
		}

		return ENTSYS_SUCCESS;
		*/
	}


	const std::size_t EntityTypeManager::get_entity_types_count() const
	{
		return entity_type_buffer_map.size();
	}


	ENTSYS_RESULT EntityTypeManager::delete_entity_type(const std::string& param_entity_type_name)
	{
		// TODO: [CRITICAL] Remove all instances of this
		// entity type before removing the entity type itself!
		entity_type_buffer_map.erase(param_entity_type_name);
		return ENTSYS_SUCCESS;
	}

	
	ENTSYS_RESULT EntityTypeManager::delete_entity_type(const std::shared_ptr<EntityType>& param_entity_type_name)
	{
		// TODO: [CRITICAL] Remove all instances of this!
		// entity type before removing the entity type itself!
		return delete_entity_type(param_entity_type_name->get_type_name());
	}


	void EntityTypeManager::delete_all_entity_types_and_entity_type_instances()
	{
		entity_type_buffer_map.clear();
	}


};
};
