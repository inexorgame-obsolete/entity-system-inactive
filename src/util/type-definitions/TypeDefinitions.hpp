// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <memory>


namespace inexor {
namespace entity_system {
	

	/// These macros make initialisations shorter.
	// TODO: Replace with 'using' or 'typedef'?

    #define ENT_ATTR_TYPE           std::shared_ptr<class EntityAttributeType>
    #define ENT_ATTR_INST           std::shared_ptr<class EntityAttributeInstance>
    #define ENT_TYPE                std::shared_ptr<class EntityType>
    #define ENT_INST                std::shared_ptr<class EntityInstance>
    #define ENT_REL_TYPE            std::shared_ptr<class EntityRelationType>
    #define ENT_REL_INST            std::shared_ptr<class EntityRelationInstance>
    #define ENT_REL_ATTR_TYPE       std::shared_ptr<class EntityRelationAttributeType>
    #define ENT_REL_ATTR_INST       std::shared_ptr<class EntityRelationAttributeInstance>


};
};
