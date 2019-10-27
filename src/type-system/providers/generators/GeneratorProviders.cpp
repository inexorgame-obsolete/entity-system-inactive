#include "GeneratorProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

GeneratorProviders::GeneratorProviders(EntityTypeBuilderFactoryPtr entity_type_builder_factory, CounterProvidersPtr counter_providers, TimerProvidersPtr timer_providers, RandomProvidersPtr random_providers)
{
    this->entity_type_builder_factory = std::move(entity_type_builder_factory);
    this->counter_providers = std::move(counter_providers);
    this->timer_providers = std::move(timer_providers);
    this->random_providers = std::move(random_providers);
}

GeneratorProviders::~GeneratorProviders() = default;

void GeneratorProviders::init()
{
    entity_type_builder_factory->init();
    counter_providers->init();
    timer_providers->init();
    random_providers->init();
}

} // namespace inexor::entity_system::type_system
