// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {
	
	
	EntityAttributeTypeInstance::EntityAttributeTypeInstance(const ENT_ATTR_TYPE& ent_attr_type)
		: DataContainer(ent_attr_type->get_attribute_data_type()),
		TypeInstanceBase(ent_attr_type)
	{
		// TODO: Implement
	}


	EntityAttributeTypeInstance::~EntityAttributeTypeInstance()
	{
		// TODO: Implement!
	}


};
};
