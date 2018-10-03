// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeManager.hpp"


namespace inexor {
namespace entity_system {
    

    EntityTypeManager::EntityTypeManager()
    {
		// Error entity type.
		entity_type_ERROR = std::make_shared<EntityType>("ERROR");
	}


    EntityTypeManager::~EntityTypeManager()
    {
		// TODO: implement!
    }
	

	bool EntityTypeManager::does_entity_type_exist(const std::string& param_entity_type_name)
	{
		// Returns false is entity type does not already exist.
		return ! (entity_type_map.end() == entity_type_map.find(param_entity_type_name));
	}

	
	std::shared_ptr<EntityType> EntityTypeManager::create_entity_type(const std::string& param_new_entity_type_name)
	{
		// Check if entity type's name is not empty.
		if(0 == strcmp("", param_new_entity_type_name.c_str()))
		{
			// Return entity type error.
			return entity_type_ERROR;
		}

		// Check if entity type with this name does already exist.
		if(does_entity_type_exist(param_new_entity_type_name))
		{
			// Return entity type error.
			return entity_type_ERROR;
		}

		// Create entity type.
		std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(param_new_entity_type_name);
		// Add new entity type to global map.
		entity_type_map[param_new_entity_type_name] = new_ent_type;
		return new_ent_type;
	}


	const std::size_t EntityTypeManager::get_entity_types_count() const
	{
		return entity_type_map.size();
	}


	ENTSYS_RESULT EntityTypeManager::delete_entity_type(const std::string& param_entity_type_name)
	{
		// TODO: [CRITICAL] Remove all instances of this
		// entity type before removing the entity type itself!
		entity_type_map.erase(param_entity_type_name);
		return ENTSYS_SUCCESS;
	}

	
	ENTSYS_RESULT EntityTypeManager::delete_entity_type(const std::shared_ptr<EntityType>& param_entity_type_name)
	{
		// TODO: [CRITICAL] Remove all instances of this!
		// entity type before removing the entity type itself!
		return delete_entity_type(param_entity_type_name->get_type_name());
	}


	void EntityTypeManager::delete_all_entity_types()
	{
		entity_type_map.clear();
	}


};
};
