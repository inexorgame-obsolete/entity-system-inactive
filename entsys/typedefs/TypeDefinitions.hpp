// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <unordered_map>

#include "../entity-manager/entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"
#include "../entity-manager/entity-types-manager/entity-type/EntityType.hpp"


namespace inexor {
namespace entity_system {
	
    // By using these type definitions we can make later definitions shorter.
    
	#define ENT_ATTR_TYPE std::shared_ptr<EntityAttributeType>
	#define ENT_ATTR_TYPE_INSTANCE std::shared_ptr<EntityAttributeTypeInstance>
	#define ENT_TYPE std::shared_ptr<EntityType>
	#define ENT_TYPE_INSTANCE std::shared_ptr<EntityTypeInstance>

	#define CREATE_ENT_TYPE(x) std::make_shared<EntityType>(x)
	#define CREATE_ENT_TYPE_INSTANCE(x) std::make_shared<EntityTypeInstance>(x)
	#define CREATE_ENT_ATTR_TYPE(x,y) std::make_shared<EntityAttributeType>(x,y)
	#define CREATE_ENT_ATTR_TYPE_INSTANCE(x) std::make_shared<EntityAttributeTypeInstance>(x)

};
};
