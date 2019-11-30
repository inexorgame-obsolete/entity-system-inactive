#include "TimerFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TimerFactories::TimerFactories(TimerTickFactoryPtr timer_tick_factory)
    : LifeCycleComponent(timer_tick_factory)
{
    this->timer_tick_factory = std::move(timer_tick_factory);
}

TimerFactories::~TimerFactories() = default;

std::string TimerFactories::get_component_name()
{
    return "TimerFactories";
}

} // namespace inexor::entity_system::type_system
