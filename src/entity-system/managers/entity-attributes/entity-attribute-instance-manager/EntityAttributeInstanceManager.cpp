#include "EntityAttributeInstanceManager.hpp"

namespace inexor::entity_system {

EntityAttributeInstanceManager::EntityAttributeInstanceManager() : InstanceManagerTemplate()
{
}

EntityAttributeInstanceManager::~EntityAttributeInstanceManager() = default;

EntityAttributeInstancePtrOpt EntityAttributeInstanceManager::create_entity_attribute_instance(const EntityAttributeTypePtr &attr_type)
{
    // Create entity attribute instance.
    // Also set the data type of the attribute instance to the data type of the attribute type
    EntityAttributeInstancePtr new_ent_attr_instance = std::make_shared<EntityAttributeInstance>(attr_type);

    //
    add_instance(new_ent_attr_instance->get_GUID(), new_ent_attr_instance);

    //
    return EntityAttributeInstancePtrOpt{new_ent_attr_instance};
}

EntityAttributeInstancePtrOpt EntityAttributeInstanceManager::get_entity_attribute_instance(const xg::Guid &attr_inst_GUID) const
{
    return get_instance(attr_inst_GUID);
}

std::size_t EntityAttributeInstanceManager::delete_entity_attribute_instance(const xg::Guid &attr_inst_GUID)
{
    return delete_instance(attr_inst_GUID);
}

std::size_t EntityAttributeInstanceManager::delete_entity_attribute_instance(const EntityAttributeInstancePtr &attr_inst)
{
    return delete_instance(attr_inst);
}

std::size_t EntityAttributeInstanceManager::get_entity_attribute_instance_count() const
{
    return get_instance_count();
}

void EntityAttributeInstanceManager::delete_all_entity_attribute_instances()
{
    delete_all_instances();
}

} // namespace inexor::entity_system
