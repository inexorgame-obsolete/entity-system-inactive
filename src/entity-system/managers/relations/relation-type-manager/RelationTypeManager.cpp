#include <entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp>

#include <utility>

namespace inexor::entity_system {

RelationTypeManager::RelationTypeManager() : TypeManagerTemplate()
{
}

RelationTypeManager::~RelationTypeManager() = default;

RelationTypePtrOpt RelationTypeManager::create_relation_type(const std::string &rel_type_name, const EntityTypePtr &ent_type_source, const EntityTypePtr &ent_type_target)
{
    // Validate new relation type name.
    if (!is_type_name_valid(rel_type_name))
    {
        // This relation type does already exist.
        // TODO: Throw error message.
        return std::nullopt;
    }

    // Create new relation type.
    RelationTypePtr new_rel_type = std::make_shared<RelationType>(rel_type_name, ent_type_source, ent_type_target);

    // Add new relation type to type map.
    add_type(rel_type_name, new_rel_type->get_GUID(), new_rel_type);

    // Signal that the relation type has been created.
    notify_relation_type_created(new_rel_type);

    return RelationTypePtrOpt{new_rel_type};
}

RelationTypePtrOpt RelationTypeManager::create_relation_type(const xg::Guid &rel_type_GUID, const std::string &rel_type_name, const EntityTypePtr &ent_type_source, const EntityTypePtr &ent_type_target)
{
    // Validate new relation type name.
    if (!is_type_name_valid(rel_type_name))
    {
        // This relation type does already exist.
        // TODO: Throw error message.
        return std::nullopt;
    }

    // Check if an relation type with this GUID does already exist.
    if (does_relation_type_exist(rel_type_GUID))
    {
        // TODO: should we silently return the existing relation type instead of returning an empty optional?
        return std::nullopt;
    }

    // Create new relation type.
    RelationTypePtr new_rel_type = std::make_shared<RelationType>(rel_type_GUID, rel_type_name, ent_type_source, ent_type_target);

    // Add new relation type to type map.
    add_type(rel_type_name, new_rel_type->get_GUID(), new_rel_type);

    // Signal that the relation type has been created.
    notify_relation_type_created(new_rel_type);

    return RelationTypePtrOpt{new_rel_type};
}

bool RelationTypeManager::does_relation_type_exist(const xg::Guid &rel_type_GUID)
{
    return does_type_exist(rel_type_GUID);
}

bool RelationTypeManager::does_relation_type_exist(const std::string &rel_type_name)
{
    return does_type_exist(rel_type_name);
}

bool RelationTypeManager::does_relation_type_exist(const RelationTypePtr &rel_type)
{
    return does_relation_type_exist(rel_type->get_GUID());
}

std::size_t RelationTypeManager::get_relation_types_count() const
{
    return get_type_count();
}

RelationTypePtrOpt RelationTypeManager::get_relation_type(const xg::Guid &rel_type_GUID)
{
    if (does_type_exist(rel_type_GUID))
    {
        return RelationTypePtrOpt{get_type(rel_type_GUID)};
    }
    return std::nullopt;
}

RelationTypePtrOpt RelationTypeManager::get_relation_type(const std::string &rel_type_name)
{
    if (does_type_exist(rel_type_name))
    {
        return RelationTypePtrOpt{get_type(rel_type_name)};
    }
    return std::nullopt;
}

std::size_t RelationTypeManager::delete_relation_type(const xg::Guid &rel_type_GUID)
{
    std::size_t deleted_rel_types_count = delete_type(rel_type_GUID);
    notify_relation_type_deleted(rel_type_GUID);
    return deleted_rel_types_count;
}

std::size_t RelationTypeManager::delete_relation_type(const std::string &rel_type_name)
{
    xg::Guid rel_type_GUID = get_GUID_by_type_name(rel_type_name);
    std::size_t deleted_rel_types_count = delete_type(rel_type_name);
    notify_relation_type_deleted(rel_type_GUID);
    return deleted_rel_types_count;
}

std::size_t RelationTypeManager::delete_relation_type(const RelationTypePtr &rel_type)
{
    xg::Guid rel_type_GUID = rel_type->get_GUID();
    std::size_t deleted_rel_types_count = delete_type(rel_type_GUID);
    // Send signal.
    notify_relation_type_deleted(rel_type_GUID);
    return deleted_rel_types_count;
}

void RelationTypeManager::delete_all_relation_types()
{
    // TODO: Make sure all relation instances will be deleted before deleting the relation types.
    delete_all_types();
}

void RelationTypeManager::register_on_created(const std::shared_ptr<RelationTypeCreatedListener> &rel_type_created_listener)
{
    signal_relation_type_created.connect(std::bind(&RelationTypeCreatedListener::on_relation_type_created, rel_type_created_listener.get(), std::placeholders::_1));
}

void RelationTypeManager::register_on_deleted(const std::shared_ptr<RelationTypeDeletedListener> &rel_type_deleted_listener)
{
    signal_relation_type_deleted.connect(std::bind(&RelationTypeDeletedListener::on_relation_type_deleted, rel_type_deleted_listener.get(), std::placeholders::_1));
}

void RelationTypeManager::notify_relation_type_created(RelationTypePtr new_rel_type)
{
    signal_relation_type_created(std::move(new_rel_type));
}

void RelationTypeManager::notify_relation_type_deleted(const xg::Guid &rel_type_GUID)
{
    signal_relation_type_deleted(rel_type_GUID);
}

} // namespace inexor::entity_system
