#include "RelationAttributeTypeManager.hpp"

namespace inexor::entity_system {

RelationAttributeTypeManager::RelationAttributeTypeManager() : TypeManagerTemplate()
{
}

RelationAttributeTypeManager::~RelationAttributeTypeManager() = default;

RelationAttributeTypePtrOpt RelationAttributeTypeManager::create_relation_attribute_type(const std::string &rel_attr_type_name, const DataType &rel_attr_type_data_type, const Features &rel_attr_type_features)
{
    // Check if an entity relation attribute type
    // with this name does already exist.
    if (!is_type_name_valid(rel_attr_type_name))
    {
        // This entity relation attribute type does already exist.
        // TODO: Throw error message.

        // Since we've not created a new entity relation attribute type
        // we can now return std::nullopt thanks to std::optional.
        return std::nullopt;
    }

    // Create new entity relation attribute type
    RelationAttributeTypePtr new_rel_attr_type = std::make_shared<RelationAttributeType>(rel_attr_type_name, rel_attr_type_data_type, rel_attr_type_features);

    //
    add_type(rel_attr_type_name, new_rel_attr_type->get_GUID(), new_rel_attr_type);

    return RelationAttributeTypePtrOpt{new_rel_attr_type};
}

std::size_t RelationAttributeTypeManager::get_relation_attribute_type_count() const
{
    // Call base class method.
    return get_type_count();
}

void RelationAttributeTypeManager::delete_all_relation_attribute_types()
{
    // Call base class method.
    delete_all_types();
}

} // namespace inexor::entity_system
