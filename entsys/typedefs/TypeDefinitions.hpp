// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <unordered_map>

#include "../EntitySystem.hpp"
#include "../entity-manager/entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"
#include "../entity-manager/entity-types-manager/entity-type/EntityType.hpp"


namespace inexor {
namespace entity_system {
	
	extern std::shared_ptr<EntitySystem> entsys;

    // By using these type definitions we can make later definitions shorter.

	#define ENT_ATTR_TYPE          std::shared_ptr<EntityAttributeType>
	#define ENT_ATTR_TYPE_INSTANCE std::shared_ptr<EntityAttributeTypeInstance>
	#define ENT_TYPE               std::shared_ptr<EntityType>
	#define ENT_TYPE_INSTANCE      std::shared_ptr<EntityTypeInstance>

	#define CREATE_ENT_TYPE(x)               entsys->create_entity_type(x)
	#define CREATE_ENT_TYPE_INSTANCE(x)      entsys->create_entity_type_instance(x)
	#define CREATE_ENT_ATTR_TYPE(x,y)        entsys->create_entity_attribute_type(x,y)
	#define CREATE_ENT_ATTR_TYPE_INSTANCE(x) entsys->create_entity_attribute_type_instance(x)

};
};
