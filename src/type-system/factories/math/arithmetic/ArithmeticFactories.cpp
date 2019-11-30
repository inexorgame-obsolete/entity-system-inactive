#include "ArithmeticFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ArithmeticFactories::ArithmeticFactories(AddIntFactoryPtr add_int_factory, AddFloatFactoryPtr add_float_factory)
    : LifeCycleComponent(add_int_factory, add_float_factory)
{
    this->add_int_factory = std::move(add_int_factory);
    this->add_float_factory = std::move(add_float_factory);
}

ArithmeticFactories::~ArithmeticFactories() = default;

std::string ArithmeticFactories::get_component_name()
{
    return "ArithmeticFactories";
}

} // namespace inexor::entity_system::type_system
