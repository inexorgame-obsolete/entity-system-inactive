#include "ConverterFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ConverterFactories::ConverterFactories(IntToFloatFactoryPtr int_to_float_factory)
{
    this->int_to_float_factory = std::move(int_to_float_factory);
}

ConverterFactories::~ConverterFactories() = default;

void ConverterFactories::init()
{
    int_to_float_factory->init();
}

} // namespace inexor::entity_system::type_system
