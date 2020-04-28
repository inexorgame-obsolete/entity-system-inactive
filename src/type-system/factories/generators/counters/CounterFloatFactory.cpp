#include <type-system/factories/generators/counters/CounterFloatFactory.hpp>

#include <type-system/types/generators/counters/CounterFloat.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

CounterFloatFactory::CounterFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

CounterFloatFactory::~CounterFloatFactory() = default;

std::string CounterFloatFactory::get_component_name()
{
    return "CounterFloatFactory";
}

EntityInstancePtrOpt CounterFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(CounterFloat::TYPE_NAME)
        ->attribute(CounterFloat::MILLIS, 1000)
        ->attribute(CounterFloat::STEP, 1.0f)
        ->attribute(CounterFloat::RESET, false)
        ->attribute(CounterFloat::COUNT, 0.0f)
        ->build();
}

EntityInstancePtrOpt CounterFloatFactory::create_instance(int millis, float step)
{
    return entity_instance_builder_factory->get_builder(CounterFloat::TYPE_NAME)
        ->attribute(CounterFloat::MILLIS, millis)
        ->attribute(CounterFloat::STEP, step)
        ->attribute(CounterFloat::RESET, false)
        ->attribute(CounterFloat::COUNT, 0.0f)
        ->build();
}

EntityInstancePtrOpt CounterFloatFactory::create_instance(int millis, float step, float start_value)
{
    return entity_instance_builder_factory->get_builder(CounterFloat::TYPE_NAME)
        ->attribute(CounterFloat::MILLIS, millis)
        ->attribute(CounterFloat::STEP, step)
        ->attribute(CounterFloat::RESET, false)
        ->attribute(CounterFloat::COUNT, start_value)
        ->build();
}

} // namespace inexor::entity_system::type_system
