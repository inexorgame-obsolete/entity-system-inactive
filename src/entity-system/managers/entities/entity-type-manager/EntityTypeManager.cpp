#include "EntityTypeManager.hpp"

namespace inexor {
namespace entity_system {

	EntityTypeManager::EntityTypeManager()
	{
	}

	EntityTypeManager::~EntityTypeManager()
	{
	}

	EntityTypePtrOpt EntityTypeManager::create_entity_type(const std::string& ent_type_name)
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
		EntityTypePtr new_entity_type = std::make_shared<EntityType>(ent_type_name);

		// Call method of the template base class
        // to add the new instance to the type map.
		add_type(ent_type_name, new_entity_type->get_GUID(), new_entity_type);

		// Signal that the entity type has been created.
		notify_entity_type_created(new_entity_type);

        // Return the entity type we've just created.
        return EntityTypePtrOpt{ new_entity_type };
	}
	EntityTypePtrOpt EntityTypeManager::create_entity_type(const xg::Guid& ent_type_GUID, const std::string& ent_type_name)
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
		// Check if an entity type with this GUID does already exist.
        if(does_entity_type_exist(ent_type_GUID))
        {
            return std::nullopt;
        }

		// Add more validation here if neccesary.

		// Create a new entity type.
		EntityTypePtr new_entity_type = std::make_shared<EntityType>(ent_type_GUID, ent_type_name);

		// Call method of the template base class
        // to add the new instance to the type map.
		add_type(ent_type_name, new_entity_type->get_GUID(), new_entity_type);

		// Signal that the entity type has been created.
		notify_entity_type_created(new_entity_type);

        // Return the entity type we've just created.
        return EntityTypePtrOpt{ new_entity_type };
    }

    bool EntityTypeManager::does_entity_type_exist(const xg::Guid& ent_type_GUID)
    {
        return does_entity_type_exist(get_type(ent_type_GUID)->get_type_name());
    }

    bool EntityTypeManager::does_entity_type_exist(const std::string& ent_type_name)
	{
		return does_type_exist(ent_type_name);
	}

	bool EntityTypeManager::does_entity_type_exist(const EntityTypePtr& ent_type_shared_ptr)
	{
		return does_entity_type_exist(ent_type_shared_ptr->get_type_name());
	}

	std::size_t EntityTypeManager::get_entity_type_count() const
	{
		return get_type_count();
	}

	EntityTypePtrOpt EntityTypeManager::get_entity_type(const xg::Guid& ent_type_GUID)
    {
        if(does_type_exist(ent_type_GUID))
        {
            return EntityTypePtrOpt { get_type(ent_type_GUID) };
        }
        return std::nullopt;
    }

	EntityTypePtrOpt EntityTypeManager::get_entity_type(const std::string& ent_type_name)
    {
        if(does_type_exist(ent_type_name))
        {
            return EntityTypePtrOpt { get_type(ent_type_name) };
        }
        return std::nullopt;
    }

	std::size_t EntityTypeManager::delete_entity_type(const xg::Guid& type_GUID)
    {
		std::size_t deleted_types_count = delete_type(type_GUID);
		notify_entity_type_deleted(type_GUID);
		return deleted_types_count;
    }

	std::size_t EntityTypeManager::delete_entity_type(const std::string& ent_type_name)
	{
		xg::Guid type_GUID = get_GUID_by_type_name(ent_type_name);
		std::size_t deleted_types_count = delete_type(ent_type_name);
		notify_entity_type_deleted(type_GUID);
		return deleted_types_count;
	}

	std::size_t EntityTypeManager::delete_entity_type(const EntityTypePtr& ent_type)
	{
		xg::Guid type_GUID = ent_type->get_GUID();
		std::size_t deleted_types_count = delete_type(ent_type->get_type_name());
		notify_entity_type_deleted(type_GUID);
		return deleted_types_count;
	}

	void EntityTypeManager::delete_all_entity_types()
	{
		// TODO: Make sure all entity instances will
		// be deleted before deleting the entity types.
		delete_all_types();
	}

	void EntityTypeManager::register_on_created(std::shared_ptr<EntityTypeCreatedListener> listener)
	{
		signal_entity_type_created.connect(std::bind(&EntityTypeCreatedListener::on_entity_type_created, listener.get(), std::placeholders::_1));
	}

	void EntityTypeManager::register_on_deleted(std::shared_ptr<EntityTypeDeletedListener> listener)
	{
		signal_entity_type_deleted.connect(std::bind(&EntityTypeDeletedListener::on_entity_type_deleted, listener.get(), std::placeholders::_1));
	}

	void EntityTypeManager::notify_entity_type_created(EntityTypePtr new_entity_type)
	{
		signal_entity_type_created(new_entity_type);
	}

	void EntityTypeManager::notify_entity_type_deleted(const xg::Guid& type_GUID)
	{
		signal_entity_type_deleted(type_GUID);
	}

}
}
