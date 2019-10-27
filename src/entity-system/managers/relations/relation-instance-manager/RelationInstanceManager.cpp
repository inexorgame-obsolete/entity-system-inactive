#include "RelationInstanceManager.hpp"

#include <utility>

namespace inexor::entity_system {

RelationInstanceManager::RelationInstanceManager(std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager) : InstanceManagerTemplate()
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_instance_manager);

    // Store pointer to the entity relation attribute instance manager.
    this->relation_attribute_instance_manager = std::move(relation_attribute_instance_manager);
}

RelationInstanceManager::~RelationInstanceManager() = default;

RelationInstancePtrOpt RelationInstanceManager::create_relation_instance(const RelationTypePtr &rel_type, const EntityInstancePtr &rel_inst_source, const EntityInstancePtr &rel_inst_target)
{
    // Create a new entity relation instance.
    RelationInstancePtr new_rel_inst = std::make_shared<RelationInstance>(rel_type, rel_inst_source, rel_inst_target);

    // No wit is time to create all corresponding entity relation attribute instances.
    // Query all relation attribute types.
    std::vector<RelationAttributeTypePtr> rel_attr_types = rel_type->get_linked_attribute_types();

    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_instance_manager);

    // Create relation attribute instances.
    for (const auto &rel_attr_type : rel_attr_types)
    {
        // Create relation attribute instance.
        RelationAttributeInstancePtr linked_rel_attr_type_inst = relation_attribute_instance_manager->create_relation_attribute_instance(rel_attr_type);

        // Link relation attribute instance to this relation instance.
        new_rel_inst->register_relation_attribute_instance(rel_attr_type, linked_rel_attr_type_inst);
    }

    // Add the relation type instance to the buffer.
    add_instance(new_rel_inst->get_GUID(), new_rel_inst);

    // Signal that the relation type has been created.
    notify_relation_instance_created(new_rel_inst);

    return RelationInstancePtrOpt{new_rel_inst};
}

RelationInstancePtrOpt RelationInstanceManager::create_relation_instance(const xg::Guid &rel_inst_GUID, const RelationTypePtr &rel_type, const EntityInstancePtr &type_inst_source, const EntityInstancePtr &type_inst_target)
{
    // Check if a relation instance with this GUID does already exist.
    if (does_relation_instance_exist(rel_inst_GUID))
    {
        return std::nullopt;
    }

    // Create a new entity relation instance.
    RelationInstancePtr new_rel_inst = std::make_shared<RelationInstance>(rel_type, type_inst_source, type_inst_target);

    // No wit is time to create all corresponding entity relation attribute instances.
    // Query all relation attribute types.
    std::vector<RelationAttributeTypePtr> rel_attr_types = rel_type->get_linked_attribute_types();

    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_instance_manager);

    // Create relation attribute instances.
    for (const auto &rel_attr_type : rel_attr_types)
    {
        // Create relation attribute instance.
        RelationAttributeInstancePtr linked_rel_attr_type_inst = relation_attribute_instance_manager->create_relation_attribute_instance(rel_attr_type);

        // Link relation attribute instance to this relation instance.
        new_rel_inst->register_relation_attribute_instance(rel_attr_type, linked_rel_attr_type_inst);
    }

    // Add the relation type instance to the buffer.
    add_instance(new_rel_inst->get_GUID(), new_rel_inst);

    // Signal that the relation type has been created.
    notify_relation_instance_created(new_rel_inst);

    return RelationInstancePtrOpt{new_rel_inst};
}

bool RelationInstanceManager::does_relation_instance_exist(const xg::Guid &rel_inst_GUID)
{
    // No mutex required as this is a read-only operation.
    return does_instance_exist(rel_inst_GUID);
}

RelationInstancePtrOpt RelationInstanceManager::get_relation_instance(const xg::Guid &rel_inst_GUID)
{
    // No mutex required as this is a read-only operation.
    return get_instance(rel_inst_GUID);
}

std::size_t RelationInstanceManager::get_relation_instances_count() const
{
    // Read only, no mutex required.
    return get_instance_count();
}

std::size_t RelationInstanceManager::delete_relation_instance(const xg::Guid &rel_inst_GUID)
{
    RelationInstancePtrOpt o_rel_inst = get_relation_instance(rel_inst_GUID);
    if (o_rel_inst.has_value())
    {
        RelationInstancePtr rel_inst = o_rel_inst.value();
        xg::Guid rel_type_GUID = rel_inst->get_relation_type()->get_GUID();
        std::size_t deleted_instances_count = delete_instance(rel_inst_GUID);
        notify_relation_instance_deleted(rel_type_GUID, rel_inst_GUID);
        return deleted_instances_count;
    } else
    {
        return 0;
    }
}

std::size_t RelationInstanceManager::delete_relation_instance(const RelationInstancePtr &rel_inst)
{
    xg::Guid rel_inst_GUID = rel_inst->get_GUID();
    xg::Guid rel_type_GUID = rel_inst->get_relation_type()->get_GUID();
    std::size_t deleted_instances_count = delete_instance(rel_inst_GUID);
    notify_relation_instance_deleted(rel_type_GUID, rel_inst_GUID);
    return deleted_instances_count;
}

void RelationInstanceManager::delete_all_relation_instances()
{
    // Call template base class method.
    delete_all_instances();
}

void RelationInstanceManager::register_on_created(const xg::Guid &rel_type_GUID, const std::shared_ptr<RelationInstanceCreatedListener> &rel_inst_created_listener)
{
    if (signals_relation_instance_created.end() == signals_relation_instance_created.find(rel_type_GUID))
    {
        auto signal = std::make_shared<boost::signals2::signal<void(RelationInstancePtr)>>();
        signals_relation_instance_created.insert(std::make_pair(rel_type_GUID, signal));
    }
    signals_relation_instance_created[rel_type_GUID]->connect(std::bind(&RelationInstanceCreatedListener::on_relation_instance_created, rel_inst_created_listener.get(), std::placeholders::_1));
}

void RelationInstanceManager::register_on_deleted(const xg::Guid &rel_type_GUID, const std::shared_ptr<RelationInstanceDeletedListener> &rel_inst_deleted_listener)
{
    if (signals_relation_instance_deleted.end() == signals_relation_instance_deleted.find(rel_type_GUID))
    {
        auto signal = std::make_shared<boost::signals2::signal<void(const xg::Guid &, const xg::Guid &)>>();
        signals_relation_instance_deleted.insert(std::make_pair(rel_type_GUID, signal));
    }
    signals_relation_instance_deleted[rel_type_GUID]->connect(std::bind(&RelationInstanceDeletedListener::on_relation_instance_deleted, rel_inst_deleted_listener.get(), std::placeholders::_1, std::placeholders::_2));
}

void RelationInstanceManager::notify_relation_instance_created(const RelationInstancePtr &rel_inst)
{
    xg::Guid rel_type_GUID = rel_inst->get_relation_type()->get_GUID();
    if (!(signals_relation_instance_created.end() == signals_relation_instance_created.find(rel_type_GUID)))
    {
        signals_relation_instance_created[rel_type_GUID]->operator()(rel_inst);
    }
}

void RelationInstanceManager::notify_relation_instance_deleted(const xg::Guid &rel_type_GUID, const xg::Guid &rel_inst_GUID)
{
    if (!(signals_relation_instance_deleted.end() == signals_relation_instance_deleted.find(rel_type_GUID)))
    {
        signals_relation_instance_deleted[rel_type_GUID]->operator()(rel_type_GUID, rel_inst_GUID);
    }
}

} // namespace inexor::entity_system
