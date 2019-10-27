#include "RelationAttributeInstance.hpp"

namespace inexor::entity_system {

RelationAttributeInstance::RelationAttributeInstance(const RelationAttributeTypePtr &rel_attr_type) : InstanceBase<RelationAttributeType>(rel_attr_type), DataContainer(rel_attr_type->get_attribute_data_type())
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_attribute_instance_mutex);

    this->type = rel_attr_type->get_attribute_data_type();
}

RelationAttributeInstance::~RelationAttributeInstance() = default;

RelationAttributeTypePtr RelationAttributeInstance::get_relation_attribute_type() const
{
    // No mutex required as this is a read-only operation.
    return get_type();
}

} // namespace inexor::entity_system
