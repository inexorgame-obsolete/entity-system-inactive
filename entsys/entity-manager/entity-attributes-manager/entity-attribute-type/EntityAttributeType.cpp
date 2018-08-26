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
		// TODO: Implement!
    }

	
	ENTSYS_DATA_VALIDATION_RESULT EntityAttributeType::validate()
	{
		// TODO: Implement!
		// TODO: Validate DataContainer ?
		return ENTSYS_DATA_INVALID;
	}

	
	std::string EntityAttributeType::get_entity_attribute_type_name() const
	{
		return entity_attribute_type_name;
	}


};
};
