#include "ConverterProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	ConverterProviders::ConverterProviders(
		IntToFloatEntityTypeProviderPtr int_to_float_entity_type_provider
	)
	{
		this->int_to_float_entity_type_provider = int_to_float_entity_type_provider;
	}

	ConverterProviders::~ConverterProviders()
	{
	}

	void ConverterProviders::init()
	{
	}

}
}
}
