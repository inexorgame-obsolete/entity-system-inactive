// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeManager.hpp"


namespace inexor {
namespace entity_system {
    

	EntityTypeManager::EntityTypeManager()
	{
		entity_type_error = std::make_shared<EntityType>("ERROR");
	}


	EntityTypeManager::~EntityTypeManager()
	{

	}


	bool EntityTypeManager::does_entity_type_exist(const std::string& ent_type_name)
	{
		return does_type_exist(ent_type_name);
	}


	bool EntityTypeManager::does_entity_type_exist(const std::shared_ptr<EntityType>& ent_type)
	{
		return does_entity_type_exist(ent_type->get_type_name());
	}


	std::shared_ptr<EntityType> EntityTypeManager::create_entity_type(const std::string& ent_type_name)
	{
		// Check if type with this name does already exist
		if(! is_new_type_name_valid(ent_type_name))
		{
			// This type does already exist
			// TODO: Throw error message!
			return entity_type_error;
		}
		// TODO: Add more validation here.

		// Create a new entity type instance.
		std::shared_ptr<EntityType> new_entity_type = std::make_shared<EntityType>(ent_type_name);

		// Add the new instance to the type map.
		add_type_to_map(ent_type_name, new_entity_type);
		return new_entity_type;
	}


	const std::size_t EntityTypeManager::get_entity_types_count() const
	{
		return get_type_count();
	}


	void EntityTypeManager::delete_entity_type(const std::string& ent_type_name)
	{
		delete_type(ent_type_name);
	}


	void EntityTypeManager::delete_entity_type(const std::shared_ptr<EntityType>& ent_type_name)
	{
		delete_type(ent_type_name->get_type_name());
	}


	void EntityTypeManager::delete_all_entity_types()
	{
		delete_all_types();
	}


};
};
