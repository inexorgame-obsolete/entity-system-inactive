#include "TimerProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

TimerProcessors::TimerProcessors(TimerTickProcessorPtr timer_tick_processor)
{
    this->timer_tick_processor = std::move(timer_tick_processor);
}

TimerProcessors::~TimerProcessors() = default;

void TimerProcessors::init()
{
    timer_tick_processor->init();
}

} // namespace inexor::visual_scripting
