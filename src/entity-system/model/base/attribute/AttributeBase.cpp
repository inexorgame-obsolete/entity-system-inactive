#include "AttributeBase.hpp"

namespace inexor {
namespace entity_system {

	AttributeBase::AttributeBase(const DataType& attr_data_type, const EnumSet<Feature>& features)
	{
		// Use lock guard to ensure thread safety for this write operation!
		std::lock_guard<std::mutex> lock(attribute_type_base_mutex);
		attribute_data_type = attr_data_type;
		this->features = features;
	}

	AttributeBase::~AttributeBase()
	{
	}

	DataType AttributeBase::get_attribute_data_type() const
	{
		// Read only, no mutex required.
		return attribute_data_type;
	}

	EnumSet<Feature> AttributeBase::get_attribute_features() const
	{
		// Read only, no mutex required.
		return features;
	}

};
};
