// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityRelationAttributeInstance.hpp"


namespace inexor {
namespace entity_system {


    EntityRelationAttributeInstance::EntityRelationAttributeInstance(const ENT_REL_ATTR_TYPE& param_ent_rel_attr_type)
        : InstanceBase(param_ent_rel_attr_type), DataContainer(param_ent_rel_attr_type->get_attribute_data_type())
    {
        // TODO: Implement!
    }
    
    
    EntityRelationAttributeInstance::~EntityRelationAttributeInstance()
    {
        // TODO: Implement!
    }

};
};
