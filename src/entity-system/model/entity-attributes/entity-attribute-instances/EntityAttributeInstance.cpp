#include <entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp>

namespace inexor::entity_system {

EntityAttributeInstance::EntityAttributeInstance(const EntityAttributeTypePtr &ent_attr_type) : InstanceBase<EntityAttributeType>(ent_attr_type), DataContainer(ent_attr_type->get_attribute_data_type())
{
    // Use lock guard to ensure thread safety for the following write operations!
    std::lock_guard<std::mutex> lock(entity_attribute_instance_mutex);

    this->type = ent_attr_type->get_attribute_data_type();
}

EntityAttributeInstance::~EntityAttributeInstance() = default;

EntityAttributeTypePtr EntityAttributeInstance::get_entity_attribute_type() const
{
    // No mutex required as this is a read-only operation.
    return get_type();
}

void EntityAttributeInstance::set_own_value(const DataValue &value)
{
    // Use lock guard to ensure thread safety for the following write operations!
    std::lock_guard<std::mutex> lock(entity_attribute_instance_mutex);

    own_value.Set(value);
}

void EntityAttributeInstance::toggle()
{
    // Use lock guard to ensure thread safety for the following write operations!
    std::lock_guard<std::mutex> lock(entity_attribute_instance_mutex);

    own_value.Set(!std::get<DataType::BOOL>(value.Value()));
}

} // namespace inexor::entity_system
