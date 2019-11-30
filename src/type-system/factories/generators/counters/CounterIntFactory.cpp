#include "CounterIntFactory.hpp"

#include <type-system/types/generators/counters/CounterInt.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

CounterIntFactory::CounterIntFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

CounterIntFactory::~CounterIntFactory() = default;

std::string CounterIntFactory::get_component_name()
{
    return "CounterIntFactory";
}

EntityInstancePtrOpt CounterIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(CounterInt::TYPE_NAME)
        ->attribute(CounterInt::MILLIS, 1000)
        ->attribute(CounterInt::STEP, 1)
        ->attribute(CounterInt::RESET, false)
        ->attribute(CounterInt::COUNT, 0)
        ->build();
}

EntityInstancePtrOpt CounterIntFactory::create_instance(int millis, int step)
{
    return entity_instance_builder_factory->get_builder(CounterInt::TYPE_NAME)
        ->attribute(CounterInt::MILLIS, millis)
        ->attribute(CounterInt::STEP, step)
        ->attribute(CounterInt::RESET, false)
        ->attribute(CounterInt::COUNT, 0)
        ->build();
}

EntityInstancePtrOpt CounterIntFactory::create_instance(int millis, int step, int start_value)
{
    return entity_instance_builder_factory->get_builder(CounterInt::TYPE_NAME)
        ->attribute(CounterInt::MILLIS, millis)
        ->attribute(CounterInt::STEP, step)
        ->attribute(CounterInt::RESET, false)
        ->attribute(CounterInt::COUNT, start_value)
        ->build();
}

} // namespace inexor::entity_system::type_system
