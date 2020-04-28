#include <entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp>

namespace inexor::entity_system {

EntityAttributeType::EntityAttributeType(const std::string &ent_attr_type_name, const DataType &ent_attr_type_datatype, const Features &ent_attr_type_features)
    : TypeBase(ent_attr_type_name), AttributeBase(ent_attr_type_datatype, ent_attr_type_features), GUIDBase()
{
}

EntityAttributeType::EntityAttributeType(const xg::Guid &ent_attr_type_GUID, const std::string &ent_attr_type_name, const DataType &ent_attr_type_datatype, const Features &ent_attr_type_features)
    : TypeBase(ent_attr_type_name), AttributeBase(ent_attr_type_datatype, ent_attr_type_features), GUIDBase(ent_attr_type_GUID)
{
}

EntityAttributeType::~EntityAttributeType() = default;

} // namespace inexor::entity_system
