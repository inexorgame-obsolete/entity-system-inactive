#include "ConverterProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ConverterProviders::ConverterProviders(IntToFloatEntityTypeProviderPtr int_to_float_entity_type_provider)
{
    this->int_to_float_entity_type_provider = std::move(int_to_float_entity_type_provider);
}

ConverterProviders::~ConverterProviders() = default;

void ConverterProviders::init()
{
}

} // namespace inexor::entity_system::type_system
