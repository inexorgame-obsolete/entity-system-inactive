// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {

    
    EntityAttributeType::EntityAttributeType(const std::string& param_entity_attribute_type_name)
    {
		entity_attribute_type_name = param_entity_attribute_type_name;
    }


    EntityAttributeType::~EntityAttributeType()
    {
		// TODO: implement!
    }

	
	// Implement data validation method as required by base class inheritance!
	ENTSYS_DATA_VALIDATION_RESULT EntityAttributeType::validate()
	{
		return ENTSYS_DATA_VALID;
	}

	
	std::string EntityAttributeType::get_entity_attribute_type_name() const
	{
		return entity_attribute_type_name;
	}


};
};
