// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeManager.hpp"


namespace inexor {
namespace entity_system {
    

	EntityTypeManager::EntityTypeManager()
	{
		error_entity = std::make_shared<EntityType>("ERROR");
	}


	EntityTypeManager::~EntityTypeManager()
	{

	}


	bool EntityTypeManager::does_entity_type_exist(const std::string& param_entity_type_name)
	{
		return does_type_exist(param_entity_type_name);
	}


	std::shared_ptr<EntityType> EntityTypeManager::create_entity_type(const std::string& param_new_entity_type_name)
	{
		// Check if type with this name does already exist
		if (does_type_exist(param_new_entity_type_name))
		{
			// This type does already exist
			// TODO: Throw error message!
			return error_entity;
		}

		if (0 == param_new_entity_type_name.compare(std::string("")))
		{
			// This type does already exist
			// TODO: Throw error message!
			return error_entity;
		}
		// TODO: Further validation!!

		std::shared_ptr<EntityType> new_entity_type = std::make_shared<EntityType>(param_new_entity_type_name);
		type_map[param_new_entity_type_name] = new_entity_type;
		return new_entity_type;
	}


	const std::size_t EntityTypeManager::get_entity_types_count() const
	{
		return get_type_count();
	}


	void EntityTypeManager::delete_entity_type(const std::string& param_entity_type_name)
	{
		// TODO: Delete all instances!
		delete_type(param_entity_type_name);
	}


	void EntityTypeManager::delete_entity_type(const std::shared_ptr<EntityType>& param_entity_type)
	{
		// TODO: Delete all instances!
		delete_type(param_entity_type->get_type_name());
	}


	void EntityTypeManager::delete_all_entity_types()
	{
		// TODO: Delete all instances!
		// Call template class method.
		delete_all_types();
	}



};
};
