// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationAttributeType.hpp"


namespace inexor {
namespace entity_system {


	RelationAttributeType::RelationAttributeType(const std::string& rel_attr_type_name, const DataType& rel_attr_type_data_type)
        : TypeBase(rel_attr_type_name), AttributeBase(rel_attr_type_data_type)
	{
		// TODO: Implement
	}


	RelationAttributeType::~RelationAttributeType()
	{
		// TODO: Implement!
	}
		
	
	ENTSYS_DATA_VALIDATION_RESULT RelationAttributeType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
