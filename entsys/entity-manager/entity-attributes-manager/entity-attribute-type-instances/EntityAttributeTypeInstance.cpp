// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {
	
	
	EntityAttributeTypeInstance::EntityAttributeTypeInstance(const std::shared_ptr<EntityAttributeType>& ent_attr_type) :
		DataContainer(ent_attr_type->get_attribute_data_type())
	{
		set_type_pointer(ent_attr_type);
		set_type_name(ent_attr_type->get_type_name());
	}


	EntityAttributeTypeInstance::~EntityAttributeTypeInstance()
	{
	}


};
};
