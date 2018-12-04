// Inexor entity system prototype
// (c)2018 Inexor

#include "AttributeBase.hpp"


namespace inexor {
namespace entity_system {


	AttributeBase::AttributeBase()
	{
		// TODO: Implement!
	}


	AttributeBase::~AttributeBase()
	{
		// TODO: Implement!
	}


	void AttributeBase::set_attribute_data_type(const ENTSYS_DATA_TYPE& attr_data_type)
	{
		attribute_data_type = attr_data_type;
	}
			

	ENTSYS_DATA_TYPE AttributeBase::get_attribute_data_type() const
	{
		return attribute_data_type;
	}


};
};
