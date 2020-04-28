#include <entity-system/model/relations/relation-instances/RelationInstance.hpp>

namespace inexor::entity_system {

RelationInstance::RelationInstance(const RelationTypePtr &rel_type, const EntityInstancePtr &ent_inst_source, const EntityInstancePtr &ent_inst_target) : GUIDBase(), InstanceBase(rel_type)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_instance_mutex);

    // Store source entity instances.
    source_entity_instance = ent_inst_source;

    // Store target entity instances.
    destination_entity_instance = ent_inst_target;
}

RelationInstance::RelationInstance(const xg::Guid &inst_GUID, const RelationTypePtr &rel_type, const EntityInstancePtr &ent_inst_source, const EntityInstancePtr &ent_inst_target) : GUIDBase(inst_GUID), InstanceBase(rel_type)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_instance_mutex);

    // Store source entity instances.
    source_entity_instance = ent_inst_source;

    // Store target entity instances.
    destination_entity_instance = ent_inst_target;
}

RelationInstance::~RelationInstance() = default;

void RelationInstance::register_relation_attribute_instance(const RelationAttributeTypePtr &rel_attr_type, const RelationAttributeInstancePtr &rel_attr_inst)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_instance_mutex);

    // Add relation attribute instance.
    relation_attribute_instances[rel_attr_type] = rel_attr_inst;
}

RelationTypePtr RelationInstance::get_relation_type() const
{
    // No mutex required as this is a read-only operation.
    return get_type();
}

std::unordered_map<RelationAttributeTypePtr, RelationAttributeInstancePtr> RelationInstance::get_relation_attribute_instances() const
{
    // No mutex required as this is a read-only operation.
    return relation_attribute_instances;
}

EntityInstancePtr RelationInstance::get_source_entity_instance() const
{
    // No mutex required as this is a read-only operation.
    return source_entity_instance;
}

EntityInstancePtr RelationInstance::get_target_entity_instance() const
{
    // No mutex required as this is a read-only operation.
    return destination_entity_instance;
}

} // namespace inexor::entity_system
