#include "CounterProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

CounterProviders::CounterProviders(CounterIntEntityTypeProviderPtr counter_int_entity_type_provider, CounterFloatEntityTypeProviderPtr counter_float_entity_type_provider)
{
    this->counter_int_entity_type_provider = std::move(counter_int_entity_type_provider);
    this->counter_float_entity_type_provider = std::move(counter_float_entity_type_provider);
}

CounterProviders::~CounterProviders() = default;

void CounterProviders::init()
{
}

} // namespace inexor::entity_system::type_system
