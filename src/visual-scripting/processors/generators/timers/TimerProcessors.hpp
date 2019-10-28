#pragma once

#include "visual-scripting/processors/generators/timers/TimerTickProcessor.hpp"

namespace inexor::visual_scripting {

using TimerTickProcessorPtr = std::shared_ptr<TimerTickProcessor>;

/// @class TimerProcessors
/// @brif Provides processors for timers.
class TimerProcessors
{
    public:
    /// @brief Constructs the processors for timers.
    /// @note The dependencies of this class will be injected automatically.
    /// @param timer_tick_processor Processor for the entity type TIMER_TICK.
    explicit TimerProcessors(TimerTickProcessorPtr timer_tick_processor);

    /// Destructor.
    ~TimerProcessors();

    /// Initialization of the processors for timers.
    void init();

    private:
    /// Processor for the entity type TIMER_TICK.
    TimerTickProcessorPtr timer_tick_processor;
};

} // namespace inexor::visual_scripting
