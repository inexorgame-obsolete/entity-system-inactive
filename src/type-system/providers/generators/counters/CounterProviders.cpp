#include "CounterProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	CounterProviders::CounterProviders(
		CounterIntEntityTypeProviderPtr counter_int_entity_type_provider,
		CounterFloatEntityTypeProviderPtr counter_float_entity_type_provider
	)
	{
		this->counter_int_entity_type_provider = counter_int_entity_type_provider;
		this->counter_float_entity_type_provider = counter_float_entity_type_provider;
	}

	CounterProviders::~CounterProviders()
	{
	}

	void CounterProviders::init()
	{
	}

}
}
}
