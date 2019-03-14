#include "ComparisonProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	ComparisonProviders::ComparisonProviders(
		EqualsBoolEntityTypeProviderPtr equals_bool_entity_type_provider,
		EqualsIntEntityTypeProviderPtr equals_int_entity_type_provider,
		EqualsStringEntityTypeProviderPtr equals_string_entity_type_provider,
		GreaterThanIntEntityTypeProviderPtr greater_than_int_entity_type_provider,
		GreaterThanFloatEntityTypeProviderPtr greater_than_float_entity_type_provider,
		LowerThanIntEntityTypeProviderPtr lower_than_int_entity_type_provider,
		LowerThanFloatEntityTypeProviderPtr lower_than_float_entity_type_provider,
		InRangeIntEntityTypeProviderPtr in_range_int_entity_type_provider,
		InRangeFloatEntityTypeProviderPtr in_range_float_entity_type_provider
	)
	{
		this->equals_bool_entity_type_provider = equals_bool_entity_type_provider;
		this->equals_int_entity_type_provider = equals_int_entity_type_provider;
		this->equals_string_entity_type_provider = equals_string_entity_type_provider;
		this->greater_than_int_entity_type_provider = greater_than_int_entity_type_provider;
		this->greater_than_float_entity_type_provider = greater_than_float_entity_type_provider;
		this->lower_than_int_entity_type_provider = lower_than_int_entity_type_provider;
		this->lower_than_float_entity_type_provider = lower_than_float_entity_type_provider;
		this->in_range_int_entity_type_provider = in_range_int_entity_type_provider;
		this->in_range_float_entity_type_provider = in_range_float_entity_type_provider;
	}

	ComparisonProviders::~ComparisonProviders()
	{
	}

	void ComparisonProviders::init()
	{
	}

}
}
}
