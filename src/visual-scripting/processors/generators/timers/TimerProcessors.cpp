#include "TimerProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

TimerProcessors::TimerProcessors(TimerTickProcessorPtr timer_tick_processor)
    : LifeCycleComponent(timer_tick_processor)
{
    this->timer_tick_processor = std::move(timer_tick_processor);
}

TimerProcessors::~TimerProcessors() = default;

std::string TimerProcessors::get_component_name()
{
    return "TimerProcessors";
}

} // namespace inexor::visual_scripting
