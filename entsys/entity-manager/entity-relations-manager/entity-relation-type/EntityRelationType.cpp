// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "EntityRelationType.hpp"


namespace inexor {
namespace entity_system {


	EntityRelationType::EntityRelationType(const std::string& param_relation_type_name,
		                                   const std::shared_ptr<EntityType>& param_source_type,
		                                   const std::shared_ptr<EntityType>& param_destination_type)
	{
		set_type_name(param_relation_type_name);
		source_entity_type = param_source_type;
		destination_entity_type = param_destination_type;
	}


	EntityRelationType::~EntityRelationType()
	{
		// TODO: Implement!
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityRelationType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}
	
	
	ENTSYS_RESULT EntityRelationType::link_entity_relation_attribute_type()
	{
		// TODO: Implement!
		return ENTSYS_ERROR;
	}


};
};
