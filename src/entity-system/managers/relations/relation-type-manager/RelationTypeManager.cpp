// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationTypeManager.hpp"


namespace inexor {
namespace entity_system {


    RelationTypeManager::RelationTypeManager() : TypeManagerTemplate()
    {
		// TODO: Implement!
    }


    RelationTypeManager::~RelationTypeManager()
    {
		// TODO: Implement!
    }


	bool RelationTypeManager::does_relation_type_exist(const std::string& rel_type_name)
	{
        // 
		return does_type_exist(rel_type_name);
	}


	bool RelationTypeManager::does_relation_type_exist(const REL_TYPE& rel_type)
	{
        // 
		return does_relation_type_exist(rel_type->get_type_name());
	}


	O_REL_TYPE RelationTypeManager::create_relation_type(const std::string& rel_type_name, const ENT_TYPE& ent_type_source, const ENT_TYPE& ent_type_target)
	{
		// Validate new entity relation type name.
		if(!is_type_name_valid(rel_type_name))
		{
			// This entity relation type does already exist.
			// TODO: Throw error message.

            // Since we've not created a new entity relation type we can
            // now return std::nullopt thanks to std::optional.
            return std::nullopt;
		}

		// Create new entity relation type.
		REL_TYPE new_relation_type = std::make_shared<RelationType>(rel_type_name, ent_type_source, ent_type_target);

		// Add new entity relation type to type map.
		add_type(rel_type_name, new_relation_type->get_GUID(), new_relation_type);

		// Signal that the relation type has been created.
		notify_relation_type_created(new_relation_type);

        return O_REL_TYPE { new_relation_type };
	}


	std::size_t RelationTypeManager::get_relation_types_count() const
	{
        // 
		return get_type_count();
	}


	std::size_t RelationTypeManager::delete_relation_type(const std::string& rel_type_name)
	{
		xg::Guid type_GUID = get_GUID_by_type_name(rel_type_name);
		std::size_t deleted_types_count = delete_type(rel_type_name);
		notify_relation_type_deleted(type_GUID);
		return deleted_types_count;
	}


	std::size_t RelationTypeManager::delete_relation_type(const xg::Guid& type_GUID)
    {
		std::size_t deleted_types_count = delete_type(type_GUID);
		notify_relation_type_deleted(type_GUID);
		return deleted_types_count;
    }

	
	std::size_t RelationTypeManager::delete_relation_type(const REL_TYPE& rel_type)
	{
		xg::Guid type_GUID = rel_type->get_GUID();
		std::size_t deleted_types_count = delete_type(rel_type->get_type_name());
		notify_relation_type_deleted(type_GUID);
		return deleted_types_count;

	}


	void RelationTypeManager::delete_all_relation_types()
	{
		// TODO: Make sure all relation instances will
		// be deleted before deleting the relation types.
		delete_all_types();
	}


	void RelationTypeManager::register_on_created(std::shared_ptr<RelationTypeCreatedListener> listener)
	{
		signal_relation_type_created.connect(std::bind(&RelationTypeCreatedListener::on_relation_type_created, listener.get(), std::placeholders::_1));
	}


	void RelationTypeManager::register_on_deleted(std::shared_ptr<RelationTypeDeletedListener> listener)
	{
		signal_relation_type_deleted.connect(std::bind(&RelationTypeDeletedListener::on_relation_type_deleted, listener.get(), std::placeholders::_1));
	}


	void RelationTypeManager::notify_relation_type_created(REL_TYPE new_entity_type)
	{
		signal_relation_type_created(new_entity_type);
	}


	void RelationTypeManager::notify_relation_type_deleted(const xg::Guid& type_GUID)
	{
		signal_relation_type_deleted(type_GUID);
	}


};
};
