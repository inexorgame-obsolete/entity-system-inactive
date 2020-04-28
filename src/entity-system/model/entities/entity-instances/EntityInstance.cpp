#include <entity-system/model/entities/entity-instances/EntityInstance.hpp>

namespace inexor::entity_system {

EntityInstance::EntityInstance(const EntityTypePtr &ent_type) : GUIDBase(), InstanceBase(ent_type)
{
}

EntityInstance::EntityInstance(const xg::Guid &ent_inst_GUID, const EntityTypePtr &ent_type) : GUIDBase(ent_inst_GUID), InstanceBase(ent_type)
{
}

EntityInstance::~EntityInstance() = default;

EntityTypePtr EntityInstance::get_entity_type() const
{
    // No mutex required as this is a read-only operation.
    return get_type();
}

void EntityInstance::add_entity_attribute_instance(const EntityAttributeTypePtr &ent_attr_type, const EntityAttributeInstancePtr &ent_attr_inst)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_instance_mutex);

    instances[ent_attr_type] = ent_attr_inst;
}

/// TODO: don't return an optional but just an empty map!
std::optional<std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>> EntityInstance::get_instances() const
{
    if (instances.empty())
    {
        // No mutex required as this is a read-only operation.
        return std::nullopt;
    }
    // No mutex required as this is a read-only operation.
    return std::optional<std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>>{instances};
}

EntityAttributeInstancePtrOpt EntityInstance::get_attribute_instance(const std::string &attr_name)
{
    for (auto &ent_attr_entry : instances)
    {
        if (attr_name == ent_attr_entry.first->get_type_name())
        {
            // No mutex required as this is a read-only operation.
            return EntityAttributeInstancePtrOpt{ent_attr_entry.second};
        }
    }
    // No mutex required as this is a read-only operation.
    return std::nullopt;
}

EntityAttributeInstancePtrOpt EntityInstance::operator[](const std::string &attr_name)
{
    for (auto &ent_attr_entry : instances)
    {
        if (attr_name == ent_attr_entry.first->get_type_name())
        {
            // No mutex required as this is a read-only operation.
            return EntityAttributeInstancePtrOpt{ent_attr_entry.second};
        }
    }
    // No mutex required as this is a read-only operation.
    return std::nullopt;
}

void EntityInstance::set_own_value(const std::string &attr_name, const DataValue &value)
{
    EntityAttributeInstancePtr attr = get_attribute_instance(attr_name).value();

    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_instance_mutex);

    attr->own_value.Set(value);
}

void EntityInstance::toggle(const std::string &attr_name)
{
    EntityAttributeInstancePtr attr = get_attribute_instance(attr_name).value();

    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_instance_mutex);

    // Toggle the value of the bool container.
    attr->own_value.Set(!attr->get<DataType::BOOL>());
}

} // namespace inexor::entity_system
