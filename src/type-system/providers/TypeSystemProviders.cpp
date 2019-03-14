#include "TypeSystemProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TypeSystemProviders::TypeSystemProviders(
		EntityTypeBuilderFactoryPtr entity_type_builder_factory,
		DataProvidersPtr data_providers,
		GeneratorProvidersPtr generator_providers,
		InOutProvidersPtr in_out_providers,
		MathProvidersPtr math_providers,
		LogicalProvidersPtr logical_providers
	)
	{
		this->entity_type_builder_factory = entity_type_builder_factory;
		this->data_providers = data_providers;
		this->generator_providers = generator_providers;
		this->in_out_providers = in_out_providers;
		this->math_providers = math_providers;
		this->logical_providers = logical_providers;
	}

	TypeSystemProviders::~TypeSystemProviders()
	{
	}

	void TypeSystemProviders::init()
	{
		entity_type_builder_factory->init();
		data_providers->init();
		generator_providers->init();
		in_out_providers->init();
		math_providers->init();
		logical_providers->init();
	}

}
}
}
