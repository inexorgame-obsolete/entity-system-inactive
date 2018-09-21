// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	EntityAttributeTypeInstance::EntityAttributeTypeInstance(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type)
		                                                     : DataContainer(param_entity_attribute_type->get_entity_attribute_data_type()) // Initialise DataContainer class
	{
		pointer_to_entity_attribute_type = param_entity_attribute_type;
	}


	EntityAttributeTypeInstance::EntityAttributeTypeInstance() : DataContainer(ENTSYS_DATA_TYPE_UNDEFINED)
	{
		// TODO: Implement!
	}


	EntityAttributeTypeInstance::~EntityAttributeTypeInstance()
	{
		// TODO: Implement!
	}


	void EntityAttributeTypeInstance::set_entity_attribute_type(const std::shared_ptr<EntityAttributeType>& param_pointer_to_ent_attr_type)
	{
		pointer_to_entity_attribute_type = param_pointer_to_ent_attr_type;
		// Reset memory of DataContainer instance when changing the entity attribute type!
		reset_memory();
	}


	std::shared_ptr<EntityAttributeType> EntityAttributeTypeInstance::get_entity_attribute_type() const
	{
		return pointer_to_entity_attribute_type;
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
