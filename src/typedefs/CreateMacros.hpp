// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <unordered_map>

#include "../EntitySystem.hpp"


namespace inexor {
namespace entity_system {
	

	// The create macros depend on the entity system.
	extern std::shared_ptr<EntitySystem> entsys;

	// Instance create macros for the entity system.
	// TODO: Give macro parameters better names than x,y,z!
	#define CREATE_ENT_TYPE(x)               entsys->create_entity_type(x)
	#define CREATE_ENT_TYPE_INSTANCE(x)      entsys->create_entity_type_instance(x)
	#define CREATE_ENT_ATTR_TYPE(x,y)        entsys->create_entity_attribute_type(x,y)
	#define CREATE_ENT_ATTR_TYPE_INSTANCE(x) entsys->create_entity_attribute_type_instance(x)
	#define CREATE_ENT_REL_TYPE(x,y,z)       entsys->create_entity_relation_type(x,y,z)
    #define CREATE_ENT_REL_TYPE_INSTANCE(x)  entsys->create_entity_relation_type_instance(x)


};
};
