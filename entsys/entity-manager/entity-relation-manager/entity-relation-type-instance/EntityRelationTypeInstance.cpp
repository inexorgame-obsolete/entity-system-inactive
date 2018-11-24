// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "EntityRelationTypeInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {

	
	extern std::shared_ptr<EntitySystem> entsys;


	EntityRelationTypeInstance::EntityRelationTypeInstance(const std::shared_ptr<EntityRelationType>& ent_rel_type,
		                                                   const std::shared_ptr<EntityTypeInstance>& ent_type_inst_source,
		                                                   const std::shared_ptr<EntityTypeInstance>& ent_type_inst_target)
	{
		// Store a pointer to the entity relation type.
		set_type_pointer(ent_rel_type);

		// Store source and target entity type instances.
		source_entity_type_instance = ent_type_inst_source;
		destination_entity_type_instance = ent_type_inst_target;

		// Create all entity relation attribute type instances.
		std::vector<std::shared_ptr<EntityRelationAttributeType>> ent_rel_attributes = ent_rel_type->get_linked_attribute_types();

		for(std::size_t i=0; i<ent_rel_attributes.size(); i++)
		{
			relation_attribute_instances[ent_rel_attributes[i]] = entsys->create_entity_relation_attribute_type_instance(ent_rel_attributes[i]);
		}
	}


	EntityRelationTypeInstance::~EntityRelationTypeInstance()
	{
		// TODO: Delete all entity relation attribute type instances!
	}

	
};
};
