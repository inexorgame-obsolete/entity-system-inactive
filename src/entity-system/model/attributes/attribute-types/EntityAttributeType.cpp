// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {


	EntityAttributeType::EntityAttributeType(const std::string& ent_attr_type_name, const ENTSYS_DATA_TYPE& ent_attr_type_datatype)
        : TypeBase(ent_attr_type_name), AttributeBase(ent_attr_type_datatype), GUIDBase()
	{
		// TODO: Implement!
	}


    EntityAttributeType::EntityAttributeType(const xg::Guid& ent_attr_type_GUID, const std::string& ent_attr_type_name, const ENTSYS_DATA_TYPE& ent_attr_type_datatype)
        : TypeBase(ent_attr_type_name), AttributeBase(ent_attr_type_datatype), GUIDBase(ent_attr_type_GUID)
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
