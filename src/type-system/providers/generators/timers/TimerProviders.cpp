#include "TimerProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TimerProviders::TimerProviders(TimerTickEntityTypeProviderPtr timer_tick_entity_type_provider)
{
    this->timer_tick_entity_type_provider = std::move(timer_tick_entity_type_provider);
}

TimerProviders::~TimerProviders() = default;

void TimerProviders::init()
{
}

} // namespace inexor::entity_system::type_system
