// Inexor entity system prototype
// (c)2018-2019 Inexor

#include "AttributeBase.hpp"


namespace inexor {
namespace entity_system {

	   
	AttributeBase::AttributeBase(const ENTSYS_DATA_TYPE& attr_data_type)
	{
		// Use lock guard to ensure thread safety for this write operation!
		std::lock_guard<std::mutex> lock(attribute_type_base_mutex);
		attribute_data_type = attr_data_type;
	}


	AttributeBase::~AttributeBase()
	{
		// TODO: Implement!
	}
			

	ENTSYS_DATA_TYPE AttributeBase::get_attribute_data_type() const
	{
        // Read only, no mutex required.
		return attribute_data_type;
	}


};
};
