// Inexor entity system prototype
// (c)2018 Inexor

#include "AttributeTypeBase.hpp"


namespace inexor {
namespace entity_system {

	   
	AttributeTypeBase::AttributeTypeBase(const ENTSYS_DATA_TYPE& attr_data_type)
	{
		attribute_data_type = attr_data_type;
	}


	AttributeTypeBase::~AttributeTypeBase()
	{
		// TODO: Implement!
	}
			

	ENTSYS_DATA_TYPE AttributeTypeBase::get_attribute_data_type() const
	{
		return attribute_data_type;
	}


};
};
