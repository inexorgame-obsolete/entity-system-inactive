// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <unordered_map>

#include "../EntitySystem.hpp"


namespace inexor {
namespace entity_system {
	

	// The create macros require an instance of the entity system.
	extern std::shared_ptr<EntitySystem> entsys;


	/// Macro for creating an entity type with EntityTypeManager.
	#define CREATE_ENT_TYPE(name)\
		entsys->create_entity_type(name)

	/// Macro for creating an entity type instance with EntityTypeInstanceManager.
	#define CREATE_ENT_TYPE_INSTANCE(ent_type)\
		entsys->create_entity_type_instance(ent_type)

	/// Create an entity attribute type with EntityAttributeTypeManager.
	#define CREATE_ENT_ATTR_TYPE(name, data_type)\
		entsys->create_entity_attribute_type(name, data_type)

	/// Create an entity attribute type instance with EntityAttributeTypeInstanceManager.
	#define CREATE_ENT_ATTR_TYPE_INSTANCE(ent_attr_type)\
		entsys->create_entity_attribute_type_instance(ent_attr_type)

	/// Create an entity relation type with EntityRelationTypeManager.
	#define CREATE_ENT_REL_TYPE(name, source_enttype, target_enttype)\
		entsys->create_entity_relation_type(name, source_enttype, target_enttype)

	/// Create an entity relation type instance with EntityRelationTypeInstanceManager.
    #define CREATE_ENT_REL_TYPE_INSTANCE(ent_rel_type)\
		entsys->create_entity_relation_type_instance(ent_rel_type)

	/// Create an entity relation attribute type with EntityRelationAttributeTypeManager.
	#define CREATE_ENT_REL_ATTR_TYPE(ent_rel_attr_type_name)\
		entsys->create_entity_relation_attribute_type(ent_rel_attr_type_name)

	/// Create an entity relation attribute type instance with EntityRelationAttributeTypeInstanceManager.
	#define CREATE_ENT_REL_ATTR_TYPE_INSTANCE(ent_rel_attr_type)\
		entsys->create_entity_relation_attribute_type_instance(ent_rel_attr_type)


	// TODO: Macros for deleting.
	// TODO: Macros for getting.
	// TODO: Macros for modifying.


};
};
