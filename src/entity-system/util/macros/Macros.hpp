// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <memory>
#include <unordered_map>

#include "entity-system/EntitySystem.hpp"


namespace inexor {
namespace entity_system {
	

	/// The create macros depend on an instance
	/// of the entity system.
	extern std::shared_ptr<EntitySystem> entity_system;


	/// Macro for creating an entity type
	/// with EntityTypeManager.
	#define CREATE_ENT_TYPE(ent_type_name)\
		entity_system->create_entity_type(ent_type_name)

	/// Macro for creating an entity type instance
	/// with EntityInstanceManager.
	#define CREATE_ENT_INST(ent_type)\
		entity_system->create_entity_instance(ent_type)

	/// Macro for creating an entity attribute type
	/// with EntityAttributeTypeManager.
	#define CREATE_ENT_ATTR_TYPE(ent_attr_type_name, data_type)\
		entity_system->create_entity_attribute_type(ent_attr_type_name, data_type)

	/// Macro for creating an entity attribute type instance
	/// with EntityAttributeInstanceManager.
	#define CREATE_ENT_ATTR_INST(ent_attr_type)\
		entity_system->create_entity_attribute_instance(ent_attr_type)

	/// Macro for creating an entity relation type
	/// with EntityRelationTypeManager.
	#define CREATE_ENT_REL_TYPE(ent_rel_type_namename, source_ent_type, target_ent_type)\
		entity_system->create_entity_relation_type(ent_rel_type_namename, source_ent_type, target_ent_type)

	/// Macro for creating an entity relation type instance
	/// with EntityRelationInstanceManager.
    #define CREATE_ENT_REL_INST(ent_rel_type)\
		entity_system->create_entity_relation_instance(ent_rel_type)

	/// Macro for creating an entity relation attribute type
	/// with EntityRelationAttributeTypeManager.
	#define CREATE_ENT_REL_ATTR_TYPE(ent_rel_attr_type_name)\
		entity_system->create_entity_relation_attribute_type(ent_rel_attr_type_name)

	/// Macro for creating an entity relation attribute type instance
	/// with EntityRelationAttributeInstanceManager.
	#define CREATE_ENT_REL_ATTR_INST(ent_rel_attr_type)\
		entity_system->create_entity_relation_attribute_instance(ent_rel_attr_type)


	/// Macro for deleting an entity type
	/// with EntityTypeManager.
	#define DELETE_ENT_TYPE(identifier)\
		entity_system->delete_entity_type(identifier)
	
	/// Macro for deleting an entity type instance
	/// with EntityInstanceManager.
	#define DELETE_ENT_INST(identifier)\
		entity_system->delete_entity_instance(identifier)
	
	/// Macro for deleting an entity attribute type
	/// with EntityAttributeTypeManager.
	#define DELETE_ENT_ATTR_TYPE(identifier)\
		entity_system->delete_entity_attribute_type(identifier)
	
	/// Macro for deleting an entity attribute type instance
	/// with EntityAttributeInstanceManager.
	#define DELETE_ENT_ATTR_INST(identifier)\
		entity_system->delete_entity_attribute_instance(identifier)

	/// Macro for deleting an entity relation type
	/// with EntityRelationTypeManager.
	#define DELETE_ENT_REL_TYPE(identifier)\
		entity_system->delete_entity_relation_type(identifier)

	/// Macro for deleting an entity relation type instance
	/// with EntityRelationInstanceManager.
	#define DELETE_ENT_REL_INST(identifier)\
		entity_system->delete_entity_relation_instance(identifier)

	/// Macro for deleting an entity relation attribute type
	/// with EntityRelationAttributeTypeManager.
	#define DELETE_ENT_REL_ATTR_TYPE(identifier)\
		entity_system->delete_entity_relation_attribute_type(identifier)

	/// Macro for deleting an entity relation attribute type instance
	/// with EntityRelationAttributeInstanceManager.
	#define DELETE_ENT_REL_ATTR_INST(identifier)\
		entity_system->delete_entity_relation_attribute_instance(identifier)


	// TODO: Macros GET_.
	// TODO: Macros MODIFY_.


};
};
