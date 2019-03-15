#include "GeneratorProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	GeneratorProviders::GeneratorProviders(
		EntityTypeBuilderFactoryPtr entity_type_builder_factory,
		CounterProvidersPtr counter_providers,
		TimerProvidersPtr timer_providers,
		RandomProvidersPtr random_providers
	)
	{
		this->entity_type_builder_factory = entity_type_builder_factory;
		this->counter_providers = counter_providers;
		this->timer_providers = timer_providers;
		this->random_providers = random_providers;
	}

	GeneratorProviders::~GeneratorProviders()
	{
	}

	void GeneratorProviders::init()
	{
		entity_type_builder_factory->init();
		counter_providers->init();
		timer_providers->init();
		random_providers->init();
	}

}
}
}
