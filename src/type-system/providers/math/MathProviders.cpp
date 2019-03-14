#include "MathProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	MathProviders::MathProviders(
		EntityTypeBuilderFactoryPtr entity_type_builder_factory,
		ArithmeticProvidersPtr arithmetic_providers,
		TrigonometricProvidersPtr trigonometric_providers
	)
	{
		this->entity_type_builder_factory = entity_type_builder_factory;
		this->arithmetic_providers = arithmetic_providers;
		this->trigonometric_providers = trigonometric_providers;
	}

	MathProviders::~MathProviders()
	{
	}

	void MathProviders::init()
	{
		entity_type_builder_factory->init();
		arithmetic_providers->init();
		trigonometric_providers->init();
	}

}
}
}
