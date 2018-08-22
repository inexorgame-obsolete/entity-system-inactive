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
    
	//#define ENTSYS_ENTITY_TYPE(x,y) std::shared_ptr<EntityType> x = std::make_shared<EntityType>(std::string(y));

};
};
