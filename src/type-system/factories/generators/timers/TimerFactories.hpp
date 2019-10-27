#pragma once

#include "type-system/factories/generators/timers/TimerTickFactory.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using TimerTickFactoryPtr = std::shared_ptr<TimerTickFactory>;

/// @class TimerFactories
/// @brief Provides the factories for timers.
class TimerFactories
{
    public:
    /// @brief Constructs the factories for timers.
    /// @note The dependencies of this class will be injected automatically.
    /// @param timer_tick_factory Factory for creating entity instances of type TIMER_TICK.
    explicit TimerFactories(TimerTickFactoryPtr timer_tick_factory);

    /// Destructor.
    ~TimerFactories();

    /// Initializes the factories for timers.
    void init();

    private:
    /// Factory for creating entity instances of type TIMER_TICK.
    TimerTickFactoryPtr timer_tick_factory;
};

} // namespace inexor::entity_system::type_system
