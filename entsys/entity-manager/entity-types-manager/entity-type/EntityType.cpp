// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityType.hpp"


namespace inexor {
namespace entity_system {
    

    EntityType::EntityType(const std::string& param_entity_type_name)
    {
		entity_type_name = param_entity_type_name;
	}
    

    EntityType::~EntityType()
    {
		// TODO: implement!
    }
    

	std::string EntityType::get_entity_type_name() const
	{
		return entity_type_name;
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityType::validate()
	{
		if(entity_type_name.empty()) return ENTSYS_DATA_INVALID_ENTITY_TYPE_NAME_UNDEFINED;
		// TODO: Add more neccesary data validation here

		return ENTSYS_DATA_VALID;
	}

};
};
