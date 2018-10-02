// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "EntityRelationType.hpp"

namespace inexor {
namespace entity_system {


	EntityRelationType::EntityRelationType()
	{
		// TODO: Implement!
	}


	EntityRelationType::EntityRelationType(const std::string& param_relation_type_name,
		                                   const std::shared_ptr<EntityType>& param_source_type,
		                                   const std::shared_ptr<EntityType>& param_destination_type)
	{
		relation_type_name = param_relation_type_name;
		source_type = param_source_type;
		destination_type = param_destination_type;
	}


	EntityRelationType::~EntityRelationType()
	{
		// TODO: Implement!
	}


	std::string EntityRelationType::get_relation_type_name() const
	{
		return relation_type_name;
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityRelationType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
