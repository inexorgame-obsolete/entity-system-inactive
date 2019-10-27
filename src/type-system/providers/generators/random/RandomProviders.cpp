#include "RandomProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

RandomProviders::RandomProviders(RandomNextIntEntityTypeProviderPtr random_next_int_entity_type_provider, RandomNextFloatEntityTypeProviderPtr random_next_float_entity_type_provider)
{
    this->random_next_int_entity_type_provider = std::move(random_next_int_entity_type_provider);
    this->random_next_float_entity_type_provider = std::move(random_next_float_entity_type_provider);
}

RandomProviders::~RandomProviders() = default;

void RandomProviders::init()
{
}

} // namespace inexor::entity_system::type_system
