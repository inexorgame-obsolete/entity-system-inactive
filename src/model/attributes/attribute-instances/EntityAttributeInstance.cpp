// Inexor entity system prototype
// (c)2018-2019 Inexor

#include "EntityAttributeInstance.hpp"


namespace inexor {
namespace entity_system {
	
	
	EntityAttributeInstance::EntityAttributeInstance(const ENT_ATTR_TYPE& ent_attr_type) : InstanceBase(ent_attr_type), DataContainer(ent_attr_type->get_attribute_data_type())
	{
		// TODO: Implement
	}


	EntityAttributeInstance::~EntityAttributeInstance()
	{
		// TODO: Implement!
	}


};
};
