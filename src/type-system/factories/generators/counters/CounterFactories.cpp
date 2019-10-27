#include "CounterFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

CounterFactories::CounterFactories(CounterIntFactoryPtr counter_int_factory, CounterFloatFactoryPtr counter_float_factory)
{
    this->counter_int_factory = std::move(counter_int_factory);
    this->counter_float_factory = std::move(counter_float_factory);
}

CounterFactories::~CounterFactories() = default;

void CounterFactories::init()
{
    counter_int_factory->init();
    counter_float_factory->init();
}

} // namespace inexor::entity_system::type_system
