// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationType.hpp"


namespace inexor {
namespace entity_system {


	RelationType::RelationType(const std::string& rel_type_name, const ENT_TYPE& ent_type_source, const ENT_TYPE& ent_type_target) 
		: GUIDBase(),
		  TypeBase(rel_type_name)
	{
		source_entity_type = ent_type_source;
		target_entity_type = ent_type_target;
	}


	RelationType::RelationType(const xg::Guid& rel_type_GUID, const std::string& rel_type_name, const ENT_TYPE& ent_type_source, const ENT_TYPE& ent_type_target)
		: GUIDBase(rel_type_GUID),
		  TypeBase(rel_type_name)
    {
		source_entity_type = ent_type_source;
		target_entity_type = ent_type_target;
    }


	RelationType::~RelationType()
	{
		// TODO: Implement!
	}


	void RelationType::link_relation_attribute_type(const REL_ATTR_TYPE& ent_rel_attr_type)
	{
		linked_rel_attr_types.push_back(ent_rel_attr_type);
	}


	std::vector<REL_ATTR_TYPE> RelationType::get_linked_attribute_types() const
	{
		return linked_rel_attr_types;
	}


	ENTSYS_DATA_VALIDATION_RESULT RelationType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
