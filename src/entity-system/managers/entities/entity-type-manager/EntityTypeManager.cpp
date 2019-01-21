// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityTypeManager.hpp"


namespace inexor {
namespace entity_system {
    

	EntityTypeManager::EntityTypeManager()
	{
		// TODO: Implement!
	}


	EntityTypeManager::~EntityTypeManager()
	{
		// TODO: Implement!
	}


	std::optional<ENT_TYPE> EntityTypeManager::create_entity_type(const std::string& ent_type_name)
	{
		// Check if an entity type with this name does already exist.
		if(! is_type_name_valid(ent_type_name))
		{
			// This entity type does already exist.
			// TODO: Notify error handler about this!

            // Since we've not created a new entity type we can 
            // now return std::nullopt thanks to std::optional.
            return std::nullopt;
        }

		// Add more validation here if neccesary.

		// Create a new entity type.
		ENT_TYPE new_entity_type = std::make_shared<EntityType>(ent_type_name);

		// Call method of the template base class
        // to add the new instance to the type map.
		add_type(ent_type_name, new_entity_type);

        // Return the entity type we've just created.
        return std::optional<ENT_TYPE>{ new_entity_type };
	}

    
    std::optional<ENT_TYPE> EntityTypeManager::create_entity_type(const xg::Guid& ent_type_GUID, const std::string& ent_type_name)
    {
		// Check if an entity type with this name does already exist.
		if(! is_type_name_valid(ent_type_name))
		{
			// This entity type does already exist.
			// TODO: Notify error handler about this!

            // Since we've not created a new entity type we can 
            // now return std::nullopt thanks to std::optional.
            return std::nullopt;
        }
        if(does_entity_type_exist(ent_type_GUID))
        {
            return std::nullopt;
        }

		// Add more validation here if neccesary.

		// Create a new entity type.
		ENT_TYPE new_entity_type = std::make_shared<EntityType>(ent_type_GUID, ent_type_name);

		// Call method of the template base class
        // to add the new instance to the type map.
		add_type(ent_type_name, new_entity_type);

        // Return the entity type we've just created.
        return std::optional<ENT_TYPE>{ new_entity_type };
    }


    bool EntityTypeManager::does_entity_type_exist(const xg::Guid& ent_type_GUID)
    {
        return does_entity_type_exist(get_type(ent_type_GUID)->get_type_name());
    }


    bool EntityTypeManager::does_entity_type_exist(const std::string& ent_type_name)
	{
		return does_type_exist(ent_type_name);
	}


	bool EntityTypeManager::does_entity_type_exist(const ENT_TYPE& ent_type_shared_ptr)
	{
		return does_entity_type_exist(ent_type_shared_ptr->get_type_name());
	}


    std::optional<ENT_TYPE> EntityTypeManager::get_entity_type(const xg::Guid& ent_type_GUID)
    {
        if(does_type_exist(ent_type_GUID))
        {
            return std::optional<ENT_TYPE> { get_type(ent_type_GUID) };
        }
        return std::nullopt;
    }


    std::optional<ENT_TYPE> EntityTypeManager::get_entity_type(const std::string& ent_type_name)
    {
        if(does_type_exist(ent_type_name))
        {
            return std::optional<ENT_TYPE> { get_type(ent_type_name) };
        }
        return std::nullopt;
    }


	std::size_t EntityTypeManager::get_entity_type_count() const
	{
		return get_type_count();
	}


	std::size_t EntityTypeManager::delete_entity_type(const std::string& ent_type_name)
	{
		return delete_type(ent_type_name);
	}


	std::size_t EntityTypeManager::delete_entity_type(const ENT_TYPE& ent_type_name)
	{
		return delete_type(ent_type_name->get_type_name());
	}

    
	std::size_t EntityTypeManager::delete_entity_type(const xg::Guid& type_GUID)
    {
        return delete_type(type_GUID);
    }


	void EntityTypeManager::delete_all_entity_types()
	{
		// TODO: Make sure all entity type instances will
		// be deleted before deleting the entity types.
		delete_all_types();
	}


};
};
