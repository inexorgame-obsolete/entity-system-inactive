#include "MathProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

MathProviders::MathProviders(EntityTypeBuilderFactoryPtr entity_type_builder_factory, ArithmeticProvidersPtr arithmetic_providers, TrigonometricProvidersPtr trigonometric_providers)
{
    this->entity_type_builder_factory = std::move(entity_type_builder_factory);
    this->arithmetic_providers = std::move(arithmetic_providers);
    this->trigonometric_providers = std::move(trigonometric_providers);
}

MathProviders::~MathProviders() = default;

void MathProviders::init()
{
    entity_type_builder_factory->init();
    arithmetic_providers->init();
    trigonometric_providers->init();
}

} // namespace inexor::entity_system::type_system
