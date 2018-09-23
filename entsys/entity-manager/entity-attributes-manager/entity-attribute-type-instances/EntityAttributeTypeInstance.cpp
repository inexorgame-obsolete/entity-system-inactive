// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityAttributeTypeInstance::EntityAttributeTypeInstance()
		: DataContainer(ENTSYS_DATA_TYPE_UNDEFINED)
	{
		// TODO: Implement
	}


	EntityAttributeTypeInstance::EntityAttributeTypeInstance(const std::shared_ptr<EntityAttributeType>& ent_attr_type)
    :  EntityAttributeType(ent_attr_type->get_entity_attribute_type_name(), ent_attr_type->get_entity_attribute_data_type()),
       DataContainer(ent_attr_type->get_entity_attribute_data_type())
	{
		// TODO: Implement!
	}


	EntityAttributeTypeInstance::~EntityAttributeTypeInstance()
	{
		// TODO: Implement!
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityAttributeTypeInstance::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
