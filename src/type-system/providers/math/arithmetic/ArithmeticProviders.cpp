#include "ArithmeticProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ArithmeticProviders::ArithmeticProviders(AddIntEntityTypeProviderPtr add_int_entity_type_provider, AddFloatEntityTypeProviderPtr add_float_entity_type_provider)
{
    this->add_int_entity_type_provider = std::move(add_int_entity_type_provider);
    this->add_float_entity_type_provider = std::move(add_float_entity_type_provider);
}

ArithmeticProviders::~ArithmeticProviders() = default;

void ArithmeticProviders::init()
{
}

} // namespace inexor::entity_system::type_system
