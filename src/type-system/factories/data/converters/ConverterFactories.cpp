#include "ConverterFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ConverterFactories::ConverterFactories(IntToFloatFactoryPtr int_to_float_factory, IntToStringFactoryPtr int_to_string_factory)
    : LifeCycleComponent(int_to_float_factory, int_to_string_factory)
{
    this->int_to_float_factory = std::move(int_to_float_factory);
    this->int_to_string_factory = std::move(int_to_string_factory);
}

ConverterFactories::~ConverterFactories() = default;

std::string ConverterFactories::get_component_name()
{
    return "ConverterFactories";
}

} // namespace inexor::entity_system::type_system
