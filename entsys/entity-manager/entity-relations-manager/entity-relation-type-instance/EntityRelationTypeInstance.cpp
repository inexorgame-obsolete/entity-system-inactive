// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "EntityRelationTypeInstance.hpp"

namespace inexor {
namespace entity_system {


	EntityRelationTypeInstance::EntityRelationTypeInstance()
	{
		// TODO: Implement!
	}


	EntityRelationTypeInstance::EntityRelationTypeInstance(const std::shared_ptr<EntityRelationType>& param_ent_rel_type,
		                                                   const std::shared_ptr<EntityTypeInstance>& param_source_entity_type_instance,
		                                                   const std::shared_ptr<EntityTypeInstance>& param_destination_entity_type_instance)
	{
		pointer_to_base_type = param_ent_rel_type;
		source_entity_type_instance = param_source_entity_type_instance;
		destination_entity_type_instance = param_destination_entity_type_instance;
	}


	EntityRelationTypeInstance::~EntityRelationTypeInstance()
	{
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityRelationTypeInstance::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
