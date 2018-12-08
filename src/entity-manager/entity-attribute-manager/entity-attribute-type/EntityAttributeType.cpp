// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {


	EntityAttributeType::EntityAttributeType(const std::string& ent_attr_type_name, const ENTSYS_DATA_TYPE& ent_attr_data_type)
    : AttributeTypeBase(ent_attr_data_type), TypeBase(ent_attr_type_name)
	{
		// TODO: Implement!
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


};
};
