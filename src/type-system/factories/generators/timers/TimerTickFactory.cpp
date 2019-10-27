#include "TimerTickFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TimerTickFactory::TimerTickFactory(TimerTickEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

TimerTickFactory::~TimerTickFactory() = default;

void TimerTickFactory::init()
{
}

EntityInstancePtrOpt TimerTickFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()->type(entity_type_provider->get_type())->attribute(TimerTickEntityTypeProvider::TIMER_TICK_MILLIS, 1000)->attribute(TimerTickEntityTypeProvider::TIMER_TICK_VALUE, false)->build();
}

EntityInstancePtrOpt TimerTickFactory::create_instance(int millis)
{
    return entity_instance_builder_factory->get_builder()->type(entity_type_provider->get_type())->attribute(TimerTickEntityTypeProvider::TIMER_TICK_MILLIS, millis)->attribute(TimerTickEntityTypeProvider::TIMER_TICK_VALUE, false)->build();
}

} // namespace inexor::entity_system::type_system
