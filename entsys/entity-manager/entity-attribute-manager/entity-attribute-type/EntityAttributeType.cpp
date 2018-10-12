// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {


	EntityAttributeType::EntityAttributeType(const std::string& ent_attr_type_name, const ENTSYS_DATA_TYPE& ent_attr_data_type)
	{
		// Call template base class method.
		set_type_name(ent_attr_type_name);
		// Call template base class method.
		set_attribute_data_type(ent_attr_data_type);
	}


	EntityAttributeType::~EntityAttributeType()
	{
	}

	
	ENTSYS_DATA_VALIDATION_RESULT EntityAttributeType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
