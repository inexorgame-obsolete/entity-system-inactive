#include "RelationType.hpp"

namespace inexor {
namespace entity_system {

	RelationType::RelationType(const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target)
		: GUIDBase(),
		TypeBase(rel_type_name)
	{
		source_entity_type = ent_type_source;
		target_entity_type = ent_type_target;
	}

	RelationType::RelationType(const xg::Guid& rel_type_GUID, const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target)
		: GUIDBase(rel_type_GUID),
		TypeBase(rel_type_name)
	{
		source_entity_type = ent_type_source;
		target_entity_type = ent_type_target;
	}

	RelationType::~RelationType()
	{
	}

	void RelationType::link_relation_attribute_type(const RelationAttributeTypePtr& ent_rel_attr_type)
	{
		linked_rel_attr_types.push_back(ent_rel_attr_type);
	}

	std::vector<RelationAttributeTypePtr> RelationType::get_linked_attribute_types() const
	{
		return linked_rel_attr_types;
	}

}
}
