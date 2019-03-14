#include "GeneratorProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	GeneratorProviders::GeneratorProviders(
		EntityTypeBuilderFactoryPtr entity_type_builder_factory,
		CounterProvidersPtr counter_providers
	)
	{
		this->entity_type_builder_factory = entity_type_builder_factory;
		this->counter_providers = counter_providers;
	}

	GeneratorProviders::~GeneratorProviders()
	{
	}

	void GeneratorProviders::init()
	{
		entity_type_builder_factory->init();
		counter_providers->init();
	}

}
}
}
