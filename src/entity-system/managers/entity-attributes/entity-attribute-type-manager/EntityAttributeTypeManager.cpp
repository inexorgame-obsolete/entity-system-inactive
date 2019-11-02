#include "EntityAttributeTypeManager.hpp"

namespace inexor::entity_system {

EntityAttributeTypeManager::EntityAttributeTypeManager() : TypeManagerTemplate()
{
}

EntityAttributeTypeManager::~EntityAttributeTypeManager() = default;

bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const std::string &attr_type_name)
{
    // Call template base class method.
    return does_type_exist(attr_type_name);
}

bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const xg::Guid &attr_type_GUID)
{
    // Call template base class method.
    return does_type_exist(attr_type_GUID);
}

bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const EntityAttributeTypePtr &attr_type)
{
    // Call template base class method.
    return does_type_exist(attr_type->get_GUID());
}

EntityAttributeTypePtrOpt EntityAttributeTypeManager::create_entity_attribute_type(const std::string &attr_type_name, const DataType &attr_type_datatype, const Features &attr_type_features)
{
    // Check if entity attribute type's name is not empty.
    if (!is_type_name_valid(attr_type_name))
    {
        // This entity attribute type does already exist.
        // TODO: Throw error message.

        // Since we've not created a new entity attribute type we can
        // now return std::nullopt thanks to std::optional.
        return std::nullopt;
    }

    // Create entity attribute type.
    EntityAttributeTypePtr new_ent_attr_type = std::make_shared<EntityAttributeType>(attr_type_name, attr_type_datatype, attr_type_features);

    // Call template base class method.
    add_type(attr_type_name, new_ent_attr_type->get_GUID(), new_ent_attr_type);

    return EntityAttributeTypePtrOpt{new_ent_attr_type};
}

EntityAttributeTypePtrOpt EntityAttributeTypeManager::create_entity_attribute_type(const xg::Guid &attr_type_GUID, const std::string &attr_type_name, const DataType &attr_type_datatype, const Features &attr_type_features)
{
    if (!is_type_name_valid(attr_type_name))
    {
        // This entity attribute type does already exist.
        // TODO: Throw error message.

        // Since we've not created a new entity attribute type we can
        // now return std::nullopt thanks to std::optional.
        return std::nullopt;
    }

    // Create entity attribute type.
    EntityAttributeTypePtr new_ent_attr_type = std::make_shared<EntityAttributeType>(attr_type_GUID, attr_type_name, attr_type_datatype, attr_type_features);

    // Call template base class method.
    add_type(attr_type_name, new_ent_attr_type->get_GUID(), new_ent_attr_type);

    return EntityAttributeTypePtrOpt{new_ent_attr_type};
}

EntityAttributeTypePtrOpt EntityAttributeTypeManager::get_entity_attribute_type(const std::string &attr_type_name) const
{
    /// TODO Implement!
    /*
    if(does_type_exist(type_name))
    {
        //return std::optional<EntityAttributeTypePtr> {  };
    }
    */
    return std::nullopt;
}

EntityAttributeTypePtrOpt EntityAttributeTypeManager::get_entity_attribute_type(const xg::Guid &attr_type_GUID) const
{
    return std::nullopt;
}

std::size_t EntityAttributeTypeManager::get_entity_attribute_type_count() const
{
    // Call template base class method.
    return get_type_count();
}

void EntityAttributeTypeManager::delete_entity_attribute_type(const std::string &attr_type)
{
    // Call template base class method.
    delete_type(attr_type);
}

void EntityAttributeTypeManager::delete_entity_attribute_type(const EntityAttributeTypePtr &attr_type)
{
    // Call template base class method.
    delete_type(attr_type->get_GUID());
}

void EntityAttributeTypeManager::delete_entity_attribute_type(const xg::Guid &attr_type_GUID)
{
    // Call template base class method.
    delete_type(attr_type_GUID);
}

void EntityAttributeTypeManager::delete_all_entity_attribute_types()
{
    // Call template base class method.
    delete_all_types();
}

} // namespace inexor::entity_system
