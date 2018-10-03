// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <unordered_map>

#include "../EntitySystem.hpp"
#include "../entity-manager/entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"
#include "../entity-manager/entity-types-manager/entity-type/EntityType.hpp"
#include "../entity-manager/entity-relations-manager/entity-relation-type/EntityRelationType.hpp"
#include "../entity-manager/entity-relations-manager/entity-relation-type-instance/EntityRelationTypeInstance.hpp"


namespace inexor {
namespace entity_system {
	
	 
	#define ENT_ATTR_TYPE                    std::shared_ptr<EntityAttributeType>
	#define ENT_ATTR_TYPE_INSTANCE           std::shared_ptr<EntityAttributeTypeInstance>
	#define ENT_TYPE                         std::shared_ptr<EntityType>
	#define ENT_TYPE_INSTANCE                std::shared_ptr<EntityTypeInstance>
	#define ENT_RELATION_TYPE                std::shared_ptr<EntityRelationType>
	#define ENT_RELATION_TYPE_INSTANCE       std::shared_ptr<EntityRelationTypeInstance>

	// The create macros depend on the entity system.
	extern std::shared_ptr<EntitySystem> entsys;

	#define CREATE_ENT_TYPE(x)               entsys->create_entity_type(x)
	#define CREATE_ENT_TYPE_INSTANCE(x)      entsys->create_entity_type_instance(x)
	#define CREATE_ENT_ATTR_TYPE(x,y)        entsys->create_entity_attribute_type(x,y)
	#define CREATE_ENT_ATTR_TYPE_INSTANCE(x) entsys->create_entity_attribute_type_instance(x)
	#define CREATE_ENT_REL_TYPE(x,y,z)       entsys->create_entity_relation_type(x,y,z)
    #define CREATE_ENT_REL_TYPE_INSTANCE(x)  entsys->create_entity_relation_type_instance(x)


};
};
