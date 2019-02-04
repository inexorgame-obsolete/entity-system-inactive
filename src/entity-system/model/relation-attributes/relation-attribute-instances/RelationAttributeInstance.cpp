// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationAttributeInstance.hpp"


namespace inexor {
namespace entity_system {


    RelationAttributeInstance::RelationAttributeInstance(const REL_ATTR_TYPE& param_rel_attr_type)
        : InstanceBase(param_rel_attr_type)
    {
        // TODO: Implement!
    }
    
    
    RelationAttributeInstance::~RelationAttributeInstance()
    {
        // TODO: Implement!
    }


	REL_ATTR_TYPE RelationAttributeInstance::get_relation_attribute_type() const
	{
		return get_type();
	}


};
};
