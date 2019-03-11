#include "TypeSystemProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TypeSystemProviders::TypeSystemProviders(
		EntityTypeBuilderFactoryPtr entity_type_builder_factory,
		ArithmeticProvidersPtr arithmetic_providers,
		ConsoleProvidersPtr console_providers,
		ConstantProvidersPtr constant_providers,
		ConverterProvidersPtr converter_providers,
		LoggerProvidersPtr logger_providers,
		StoreProvidersPtr store_providers,
		TrigonometricProvidersPtr trigonometric_providers
	)
	{
		this->entity_type_builder_factory = entity_type_builder_factory;
		this->arithmetic_providers = arithmetic_providers;
		this->console_providers = console_providers;
		this->constant_providers = constant_providers;
		this->converter_providers = converter_providers;
		this->logger_providers = logger_providers;
		this->store_providers = store_providers;
		this->trigonometric_providers = trigonometric_providers;
	}

	TypeSystemProviders::~TypeSystemProviders()
	{
	}

	void TypeSystemProviders::init()
	{
		entity_type_builder_factory->init();
		arithmetic_providers->init();
		console_providers->init();
		constant_providers->init();
		converter_providers->init();
		logger_providers->init();
		store_providers->init();
		trigonometric_providers->init();
	}

}
}
}
