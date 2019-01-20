// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <memory>


namespace inexor {
namespace entity_system {
	

	// TODO: Replace with 'using' or 'typedef'?

    #define ENT_ATTR_TYPE           std::shared_ptr<class EntityAttributeType>
    #define ENT_ATTR_INST           std::shared_ptr<class EntityAttributeInstance>
    #define ENT_TYPE                std::shared_ptr<class EntityType>
    #define ENT_INST                std::shared_ptr<class EntityInstance>
    #define REL_TYPE                std::shared_ptr<class RelationType>
    #define REL_INST                std::shared_ptr<class RelationInstance>
    #define REL_ATTR_TYPE           std::shared_ptr<class RelationAttributeType>
    #define REL_ATTR_INST           std::shared_ptr<class RelationAttributeInstance>


};
};
