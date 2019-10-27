#include "TimerFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TimerFactories::TimerFactories(TimerTickFactoryPtr timer_tick_factory)
{
    this->timer_tick_factory = std::move(timer_tick_factory);
}

TimerFactories::~TimerFactories() = default;

void TimerFactories::init()
{
    timer_tick_factory->init();
}

} // namespace inexor::entity_system::type_system
