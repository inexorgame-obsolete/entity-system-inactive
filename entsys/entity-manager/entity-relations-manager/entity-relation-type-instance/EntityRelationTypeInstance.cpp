// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "EntityRelationTypeInstance.hpp"

namespace inexor {
namespace entity_system {


	EntityRelationTypeInstance::EntityRelationTypeInstance(const std::shared_ptr<EntityRelationType>& ent_rel_type,
		                                                   const std::shared_ptr<EntityTypeInstance>& ent_type_inst_source,
		                                                   const std::shared_ptr<EntityTypeInstance>& ent_type_inst_target)
	{
		pointer_to_base_type = ent_rel_type;
		source_entity_type_instance = ent_type_inst_source;
		destination_entity_type_instance = ent_type_inst_target;
	}


	EntityRelationTypeInstance::~EntityRelationTypeInstance()
	{
	}

	
};
};
