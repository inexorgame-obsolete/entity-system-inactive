#include "ArithmeticFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ArithmeticFactories::ArithmeticFactories(AddIntFactoryPtr add_int_factory, AddFloatFactoryPtr add_float_factory)
{
    this->add_int_factory = std::move(add_int_factory);
    this->add_float_factory = std::move(add_float_factory);
}

ArithmeticFactories::~ArithmeticFactories() = default;

void ArithmeticFactories::init()
{
    add_int_factory->init();
    add_float_factory->init();
}

} // namespace inexor::entity_system::type_system
