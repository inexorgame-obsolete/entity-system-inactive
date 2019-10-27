#include "CounterIntFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

CounterIntFactory::CounterIntFactory(CounterIntEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

CounterIntFactory::~CounterIntFactory() = default;

void CounterIntFactory::init()
{
}

EntityInstancePtrOpt CounterIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_MILLIS, 1000)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_STEP, 1)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_RESET, false)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_COUNT, 0)
        ->build();
}

EntityInstancePtrOpt CounterIntFactory::create_instance(int millis, int step)
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_MILLIS, millis)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_STEP, step)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_RESET, false)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_COUNT, 0)
        ->build();
}

EntityInstancePtrOpt CounterIntFactory::create_instance(int millis, int step, int start_value)
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_MILLIS, millis)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_STEP, step)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_RESET, false)
        ->attribute(CounterIntEntityTypeProvider::COUNTER_INT_COUNT, start_value)
        ->build();
}

} // namespace inexor::entity_system::type_system
