#include <type-system/factories/generators/counters/CounterFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

CounterFactories::CounterFactories(CounterIntFactoryPtr counter_int_factory, CounterFloatFactoryPtr counter_float_factory)
    : LifeCycleComponent(counter_int_factory, counter_float_factory)
{
    this->counter_int_factory = std::move(counter_int_factory);
    this->counter_float_factory = std::move(counter_float_factory);
}

CounterFactories::~CounterFactories() = default;

std::string CounterFactories::get_component_name()
{
    return "CounterFactories";
}

} // namespace inexor::entity_system::type_system
