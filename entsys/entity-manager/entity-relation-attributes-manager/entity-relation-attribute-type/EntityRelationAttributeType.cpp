// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationAttributeType.hpp"


namespace inexor {
namespace entity_system {


	EntityRelationAttributeType::EntityRelationAttributeType(const std::string& ent_rel_attr_type_name,
		                                                     const ENTSYS_DATA_TYPE& ent_rel_attr_type_data_type)
	{
		set_type_name(ent_rel_attr_type_name);
		set_attribute_data_type(ent_rel_attr_type_data_type);
	}


	EntityRelationAttributeType::~EntityRelationAttributeType()
	{
	}
		
	
	ENTSYS_DATA_VALIDATION_RESULT EntityRelationAttributeType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
