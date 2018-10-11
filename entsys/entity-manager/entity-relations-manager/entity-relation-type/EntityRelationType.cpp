// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "EntityRelationType.hpp"


namespace inexor {
namespace entity_system {


	EntityRelationType::EntityRelationType(const std::string& rel_type_name,
		                                   const std::shared_ptr<EntityType>& ent_type_source,
		                                   const std::shared_ptr<EntityType>& ent_type_target)
	{
		set_type_name(rel_type_name);
		source_entity_type = ent_type_source;
		target_entity_type = ent_type_target;
	}


	EntityRelationType::~EntityRelationType()
	{
	}


	void EntityRelationType::link_entity_relation_attribute_type(const std::shared_ptr<EntityRelationAttributeType>& ent_rel_attr_type)
	{
		linked_rel_attr_types.push_back(ent_rel_attr_type);
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityRelationType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
