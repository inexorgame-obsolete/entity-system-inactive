#include "GeneratorFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

GeneratorFactories::GeneratorFactories(CounterFactoriesPtr counter_factories, TimerFactoriesPtr timer_factories, RandomFactoriesPtr random_factories)
{
    this->counter_factories = std::move(counter_factories);
    this->timer_factories = std::move(timer_factories);
    this->random_factories = std::move(random_factories);
}

GeneratorFactories::~GeneratorFactories()
{
}

void GeneratorFactories::init()
{
    counter_factories->init();
    timer_factories->init();
    random_factories->init();
}

} // namespace inexor::entity_system::type_system
