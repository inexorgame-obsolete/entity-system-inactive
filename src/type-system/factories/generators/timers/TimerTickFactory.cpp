#include "TimerTickFactory.hpp"

#include <type-system/types/generators/timers/TimerTick.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

TimerTickFactory::TimerTickFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

TimerTickFactory::~TimerTickFactory() = default;

void TimerTickFactory::init()
{
}

EntityInstancePtrOpt TimerTickFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(TimerTick::TYPE_NAME)->attribute(TimerTick::MILLIS, 1000)->attribute(TimerTick::VALUE, false)->build();
}

EntityInstancePtrOpt TimerTickFactory::create_instance(int millis)
{
    return entity_instance_builder_factory->get_builder(TimerTick::TYPE_NAME)->attribute(TimerTick::MILLIS, millis)->attribute(TimerTick::VALUE, false)->build();
}

} // namespace inexor::entity_system::type_system
