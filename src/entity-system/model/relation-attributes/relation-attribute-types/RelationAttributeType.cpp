#include <entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp>

namespace inexor::entity_system {

RelationAttributeType::RelationAttributeType(const std::string &rel_attr_type_name, const DataType &rel_attr_type_data_type, const Features &rel_attr_type_features)
    : TypeBase(rel_attr_type_name), AttributeBase(rel_attr_type_data_type, rel_attr_type_features)
{
}

RelationAttributeType::~RelationAttributeType() = default;

} // namespace inexor::entity_system
