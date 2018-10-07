// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationAttributeType.hpp"


namespace inexor {
namespace entity_system {


	EntityRelationAttributeType::EntityRelationAttributeType(const std::string& param_entity_relation_attribute_type_name,
		                                                     const ENTSYS_DATA_TYPE& param_entity_relation_attribute_data_type)
	{
		entity_relation_attribute_type_name = param_entity_relation_attribute_type_name;
		entity_relation_attribute_data_type = param_entity_relation_attribute_data_type;
	}


	EntityRelationAttributeType::~EntityRelationAttributeType()
	{
		// TODO: Implement!
	}

	
	ENTSYS_DATA_VALIDATION_RESULT EntityRelationAttributeType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


	ENTSYS_DATA_TYPE EntityRelationAttributeType::get_entity_relation_attribute_data_type() const
	{
		return entity_relation_attribute_data_type;
	}

	
	std::string EntityRelationAttributeType::get_entity_relation_attribute_type_name() const
	{
		return entity_relation_attribute_type_name;
	}


};
};
