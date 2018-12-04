// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationType.hpp"


namespace inexor {
namespace entity_system {


	EntityRelationType::EntityRelationType(const std::string& rel_type_name,
		                                   const ENT_TYPE& ent_type_source,
		                                   const ENT_TYPE& ent_type_target)
	{
		set_type_name(rel_type_name);
		source_entity_type = ent_type_source;
		target_entity_type = ent_type_target;
	}


	EntityRelationType::~EntityRelationType()
	{
		// TODO: Implement!
	}


	void EntityRelationType::link_entity_relation_attribute_type(const ENT_REL_ATTR_TYPE& ent_rel_attr_type)
	{
		linked_rel_attr_types.push_back(ent_rel_attr_type);
	}


	std::vector<ENT_REL_ATTR_TYPE> EntityRelationType::get_linked_attribute_types() const
	{
		return linked_rel_attr_types;
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityRelationType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
