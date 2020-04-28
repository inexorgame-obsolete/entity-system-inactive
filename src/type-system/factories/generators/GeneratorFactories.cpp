#include <type-system/factories/generators/GeneratorFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

GeneratorFactories::GeneratorFactories(CounterFactoriesPtr counter_factories, TimerFactoriesPtr timer_factories, RandomFactoriesPtr random_factories)
    : LifeCycleComponent(counter_factories, timer_factories, random_factories)
{
    this->counter_factories = std::move(counter_factories);
    this->timer_factories = std::move(timer_factories);
    this->random_factories = std::move(random_factories);
}

GeneratorFactories::~GeneratorFactories() = default;

std::string GeneratorFactories::get_component_name()
{
    return "GeneratorFactories";
}

} // namespace inexor::entity_system::type_system
