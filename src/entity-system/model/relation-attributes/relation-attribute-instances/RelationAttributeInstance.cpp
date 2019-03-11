#include "RelationAttributeInstance.hpp"

namespace inexor {
namespace entity_system {

    RelationAttributeInstance::RelationAttributeInstance(const RelationAttributeTypePtr& rel_attr_type)
        : InstanceBase<RelationAttributeType>(rel_attr_type),
		  DataContainer(rel_attr_type->get_attribute_data_type())
    {
		this->type = rel_attr_type->get_attribute_data_type();
    }

    RelationAttributeInstance::~RelationAttributeInstance()
    {
    }

    RelationAttributeTypePtr RelationAttributeInstance::get_relation_attribute_type() const
	{
		return get_type();
	}

}
}
