#include "ComparisonProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ComparisonProviders::ComparisonProviders(EqualsBoolEntityTypeProviderPtr equals_bool_entity_type_provider, EqualsIntEntityTypeProviderPtr equals_int_entity_type_provider, EqualsStringEntityTypeProviderPtr equals_string_entity_type_provider,
                                         GreaterThanIntEntityTypeProviderPtr greater_than_int_entity_type_provider, GreaterThanFloatEntityTypeProviderPtr greater_than_float_entity_type_provider,
                                         LowerThanIntEntityTypeProviderPtr lower_than_int_entity_type_provider, LowerThanFloatEntityTypeProviderPtr lower_than_float_entity_type_provider,
                                         InRangeIntEntityTypeProviderPtr in_range_int_entity_type_provider, InRangeFloatEntityTypeProviderPtr in_range_float_entity_type_provider)
{
    this->equals_bool_entity_type_provider = std::move(equals_bool_entity_type_provider);
    this->equals_int_entity_type_provider = std::move(equals_int_entity_type_provider);
    this->equals_string_entity_type_provider = std::move(equals_string_entity_type_provider);
    this->greater_than_int_entity_type_provider = std::move(greater_than_int_entity_type_provider);
    this->greater_than_float_entity_type_provider = std::move(greater_than_float_entity_type_provider);
    this->lower_than_int_entity_type_provider = std::move(lower_than_int_entity_type_provider);
    this->lower_than_float_entity_type_provider = std::move(lower_than_float_entity_type_provider);
    this->in_range_int_entity_type_provider = std::move(in_range_int_entity_type_provider);
    this->in_range_float_entity_type_provider = std::move(in_range_float_entity_type_provider);
}

ComparisonProviders::~ComparisonProviders() = default;

void ComparisonProviders::init()
{
}

} // namespace inexor::entity_system::type_system
