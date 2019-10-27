#include "RandomFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

RandomFactories::RandomFactories(RandomNextIntFactoryPtr random_next_int_factory, RandomNextFloatFactoryPtr random_next_float_factory)
{
    this->random_next_int_factory = std::move(random_next_int_factory);
    this->random_next_float_factory = std::move(random_next_float_factory);
}

RandomFactories::~RandomFactories() = default;

void RandomFactories::init()
{
    random_next_int_factory->init();
    random_next_float_factory->init();
}

} // namespace inexor::entity_system::type_system
