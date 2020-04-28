#include <type-system/factories/generators/random/RandomFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

RandomFactories::RandomFactories(RandomNextIntFactoryPtr random_next_int_factory, RandomNextFloatFactoryPtr random_next_float_factory)
    : LifeCycleComponent(random_next_int_factory, random_next_float_factory)
{
    this->random_next_int_factory = std::move(random_next_int_factory);
    this->random_next_float_factory = std::move(random_next_float_factory);
}

RandomFactories::~RandomFactories() = default;

std::string RandomFactories::get_component_name()
{
    return "RandomFactories";
}

} // namespace inexor::entity_system::type_system
