// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityAttributeInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityAttributeInstance::EntityAttributeInstance(const ENT_ATTR_TYPE& ent_attr_type)
        : InstanceBase<EntityAttributeType>(ent_attr_type),
		  DataContainer(ent_attr_type->get_attribute_data_type())
	{
		// TODO: Implement ... DONE?
		this->type = ent_attr_type->get_attribute_data_type();
	}


	EntityAttributeInstance::~EntityAttributeInstance()
	{
		// TODO: Implement!
	}


	ENT_ATTR_TYPE EntityAttributeInstance::get_entity_attribute_type() const
	{
		return get_type();
	}


};
};
