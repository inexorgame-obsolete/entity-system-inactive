// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityType.hpp"


namespace inexor {
namespace entity_system {
    

    EntityType::EntityType(const std::string& param_entity_type_name)
    {
		name_of_entity_type = param_entity_type_name;
	}
    

    EntityType::~EntityType()
    {
		// TODO: implement!
    }
    

	std::string EntityType::get_entity_type_name() const
	{
		return name_of_entity_type;
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityType::validate()
	{
		if(name_of_entity_type.empty()) return ENTSYS_DATA_INVALID_ENTITY_TYPE_NAME_UNDEFINED;
		// TODO: Add more neccesary data validation here

		return ENTSYS_DATA_VALID;
	}

};
};
