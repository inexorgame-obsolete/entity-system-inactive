#include "RelationTypeManager.hpp"

namespace inexor {
namespace entity_system {

	RelationTypeManager::RelationTypeManager() : TypeManagerTemplate()
	{
	}

	RelationTypeManager::~RelationTypeManager()
	{
	}

	RelationTypePtrOpt RelationTypeManager::create_relation_type(const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target)
	{
		// Validate new relation type name.
		if(!is_type_name_valid(rel_type_name))
		{
			// This relation type does already exist.
			// TODO: Throw error message.
			return std::nullopt;
		}

		// Create new relation type.
		RelationTypePtr new_relation_type = std::make_shared<RelationType>(rel_type_name, ent_type_source, ent_type_target);

		// Add new relation type to type map.
		add_type(rel_type_name, new_relation_type->get_GUID(), new_relation_type);

		// Signal that the relation type has been created.
		notify_relation_type_created(new_relation_type);

		return RelationTypePtrOpt { new_relation_type };
	}

	RelationTypePtrOpt RelationTypeManager::create_relation_type(const xg::Guid& rel_type_GUID, const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target)
	{
		// Validate new relation type name.
		if(!is_type_name_valid(rel_type_name))
		{
			// This relation type does already exist.
			// TODO: Throw error message.
			return std::nullopt;
		}

		// Check if an relation type with this GUID does already exist.
		if(does_relation_type_exist(rel_type_GUID))
		{
			return std::nullopt;
		}

		// Create new relation type.
		RelationTypePtr new_relation_type = std::make_shared<RelationType>(rel_type_GUID, rel_type_name, ent_type_source, ent_type_target);

		// Add new relation type to type map.
		add_type(rel_type_name, new_relation_type->get_GUID(), new_relation_type);

		// Signal that the relation type has been created.
		notify_relation_type_created(new_relation_type);

		return RelationTypePtrOpt { new_relation_type };
	}

	bool RelationTypeManager::does_relation_type_exist(const xg::Guid& rel_type_GUID)
	{
		return does_relation_type_exist(get_type(rel_type_GUID)->get_type_name());
	}

	bool RelationTypeManager::does_relation_type_exist(const std::string& rel_type_name)
	{
		return does_type_exist(rel_type_name);
	}

	bool RelationTypeManager::does_relation_type_exist(const RelationTypePtr& rel_type)
	{
		return does_relation_type_exist(rel_type->get_type_name());
	}

	std::size_t RelationTypeManager::get_relation_types_count() const
	{
		return get_type_count();
	}

	RelationTypePtrOpt RelationTypeManager::get_relation_type(const xg::Guid& rel_type_GUID)
	{
		if(does_type_exist(rel_type_GUID))
		{
			return RelationTypePtrOpt { get_type(rel_type_GUID) };
		}
		return std::nullopt;
	}

	RelationTypePtrOpt RelationTypeManager::get_relation_type(const std::string& rel_type_name)
	{
		if(does_type_exist(rel_type_name))
		{
			return RelationTypePtrOpt { get_type(rel_type_name) };
		}
		return std::nullopt;
	}

	std::size_t RelationTypeManager::delete_relation_type(const xg::Guid& type_GUID)
	{
		std::size_t deleted_types_count = delete_type(type_GUID);
		notify_relation_type_deleted(type_GUID);
		return deleted_types_count;
	}

	std::size_t RelationTypeManager::delete_relation_type(const std::string& rel_type_name)
	{
		xg::Guid type_GUID = get_GUID_by_type_name(rel_type_name);
		std::size_t deleted_types_count = delete_type(rel_type_name);
		notify_relation_type_deleted(type_GUID);
		return deleted_types_count;
	}

	std::size_t RelationTypeManager::delete_relation_type(const RelationTypePtr& rel_type)
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

	void RelationTypeManager::notify_relation_type_created(RelationTypePtr new_entity_type)
	{
		signal_relation_type_created(new_entity_type);
	}

	void RelationTypeManager::notify_relation_type_deleted(const xg::Guid& type_GUID)
	{
		signal_relation_type_deleted(type_GUID);
	}

}
}
