#include "RelationAttributeInstanceManager.hpp"

namespace inexor::entity_system {

RelationAttributeInstanceManager::RelationAttributeInstanceManager() : InstanceManagerTemplate()
{
}

RelationAttributeInstanceManager::~RelationAttributeInstanceManager() = default;

RelationAttributeInstancePtr RelationAttributeInstanceManager::create_relation_attribute_instance(const RelationAttributeTypePtr &rel_attr_type)
{
    // Creates a new relation attribute type instance.
    RelationAttributeInstancePtr new_rel_attr_inst = std::make_shared<RelationAttributeInstance>(rel_attr_type);

    // Call base template class method.
    add_instance(new_rel_attr_inst->get_GUID(), new_rel_attr_inst);

    // Read only, no mutex required.
    return RelationAttributeInstancePtr{new_rel_attr_inst};
}

std::optional<RelationAttributeInstancePtr> RelationAttributeInstanceManager::get_relation_attribute_instance(const xg::Guid &rel_attr_inst_GUID)
{
    if (does_instance_exist(rel_attr_inst_GUID))
    {
        return get_instance(rel_attr_inst_GUID);
    }
    return std::nullopt;
}

std::size_t RelationAttributeInstanceManager::get_relation_attribute_instance_count() const
{
    // No mutex required as this is a read-only operation.
    return get_instance_count();
}

void RelationAttributeInstanceManager::delete_all_relation_attribute_instances()
{
    // No mutex required as this is a read-only operation.
    return delete_all_instances();
}

} // namespace inexor::entity_system
