#pragma once

#include "type-system/factories/generators/counters/CounterFactories.hpp"
#include "type-system/factories/generators/random/RandomFactories.hpp"
#include "type-system/factories/generators/timers/TimerFactories.hpp"

namespace inexor::entity_system::type_system {

using CounterFactoriesPtr = std::shared_ptr<CounterFactories>;
using TimerFactoriesPtr = std::shared_ptr<TimerFactories>;
using RandomFactoriesPtr = std::shared_ptr<RandomFactories>;

/// @class GeneratorFactories
/// @brief The factories for generators like counters and timers.
class GeneratorFactories
{
    public:
    /// @brief Constructs the factories for generators like counters and timers.
    /// @note The dependencies of this class will be injected automatically.
    /// @param counter_factories The factories for counters.
    /// @param timer_factories The factories for timers.
    /// @param random_factories The factories for random number generators.
    GeneratorFactories(CounterFactoriesPtr counter_factories, TimerFactoriesPtr timer_factories, RandomFactoriesPtr random_factories);

    /// Destructor.
    ~GeneratorFactories();

    /// Initializes the factories for generators like counters and timers.
    void init();

    private:
    /// The factories for counters.
    CounterFactoriesPtr counter_factories;

    /// The factories for timers.
    TimerFactoriesPtr timer_factories;

    /// The factories for random number generators.
    RandomFactoriesPtr random_factories;
};

} // namespace inexor::entity_system::type_system
