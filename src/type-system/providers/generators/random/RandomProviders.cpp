#include "RandomProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	RandomProviders::RandomProviders(
		RandomNextIntEntityTypeProviderPtr random_next_int_entity_type_provider,
		RandomNextFloatEntityTypeProviderPtr random_next_float_entity_type_provider
	)
	{
		this->random_next_int_entity_type_provider = random_next_int_entity_type_provider;
		this->random_next_float_entity_type_provider = random_next_float_entity_type_provider;
	}

	RandomProviders::~RandomProviders()
	{
	}

	void RandomProviders::init()
	{
	}

}
}
}
