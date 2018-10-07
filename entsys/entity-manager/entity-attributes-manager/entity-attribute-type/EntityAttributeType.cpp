// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {


	void EntityAttributeType::set_data_type(const ENTSYS_DATA_TYPE& param_ent_attr_data_type)
	{
		entity_attribute_data_type = param_ent_attr_data_type;
	}


	EntityAttributeType::EntityAttributeType(const std::string& param_entity_attribute_type_name,
		                                     const ENTSYS_DATA_TYPE& param_entity_attribute_data_type)
	{
		set_type_name(param_entity_attribute_type_name);
		set_data_type(param_entity_attribute_data_type);
	}


	EntityAttributeType::~EntityAttributeType()
	{
		// TODO: Implement!
	}

	
	ENTSYS_DATA_VALIDATION_RESULT EntityAttributeType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


	ENTSYS_DATA_TYPE EntityAttributeType::get_attribute_data_type() const
	{
		return entity_attribute_data_type;
	}


};
};
