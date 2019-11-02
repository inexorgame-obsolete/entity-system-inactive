#include "AttributeBase.hpp"

namespace inexor::entity_system {

AttributeBase::AttributeBase(const DataType &attr_data_type, const Features &features)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(attribute_type_base_mutex);

    this->attribute_data_type = attr_data_type;
    this->features = features;
}

AttributeBase::~AttributeBase() = default;

DataType AttributeBase::get_attribute_data_type() const
{
    // No mutex required as this is a read-only operation.
    return attribute_data_type;
}

Features AttributeBase::get_attribute_features() const
{
    // No mutex required as this is a read-only operation.
    return features;
}

} // namespace inexor::entity_system
