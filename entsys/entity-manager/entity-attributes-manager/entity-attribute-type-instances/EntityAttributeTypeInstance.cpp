// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeInstance.hpp"
#include "../../../EntitySystem.hpp"

extern inexor::entity_system::EntitySystem* entsys;


namespace inexor {
namespace entity_system {


	EntityAttributeTypeInstance::EntityAttributeTypeInstance()
	{
		// TODO: Implement!
	}


	EntityAttributeTypeInstance::~EntityAttributeTypeInstance()
	{
		// TODO: Implement!
	}


	EntityAttributeTypeInstance::EntityAttributeTypeInstance(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type)
	{
		pointer_to_entity_attribute_type = param_entity_attribute_type;
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityAttributeTypeInstance::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


	std::string EntityAttributeTypeInstance::get_entity_attribute_type_name() const
	{
		return pointer_to_entity_attribute_type->get_entity_attribute_type_name();
	}


	ENTSYS_DATA_TYPE EntityAttributeTypeInstance::get_entity_attribute_data_type() const
	{
		return pointer_to_entity_attribute_type->get_entity_attribute_data_type();
	}


};
};
