#include "AttributeBase.hpp"

namespace inexor {
namespace entity_system {

	AttributeBase::AttributeBase(const DataType& attr_data_type, const EnumSet<Feature>& features)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(attribute_type_base_mutex);

		this->attribute_data_type = attr_data_type;
		this->features = features;
	}

	AttributeBase::~AttributeBase()
	{
	}

	DataType AttributeBase::get_attribute_data_type() const
	{
		// No mutex required as this is a read-only operation.
		return attribute_data_type;
	}

	EnumSet<Feature> AttributeBase::get_attribute_features() const
	{
		// No mutex required as this is a read-only operation.
		return features;
	}

}
}
