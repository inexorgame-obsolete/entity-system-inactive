#include "ConstantFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ConstantFactories::ConstantFactories(BoolConstantFactoryPtr bool_constant_factory, FloatConstantFactoryPtr float_constant_factory, IntConstantFactoryPtr int_constant_factory, StringConstantFactoryPtr string_constant_factory)
    : LifeCycleComponent(bool_constant_factory, float_constant_factory, int_constant_factory, string_constant_factory)
{
    this->bool_constant_factory = std::move(bool_constant_factory);
    this->float_constant_factory = std::move(float_constant_factory);
    this->int_constant_factory = std::move(int_constant_factory);
    this->string_constant_factory = std::move(string_constant_factory);
}

ConstantFactories::~ConstantFactories() = default;

std::string ConstantFactories::get_component_name()
{
    return "ConstantFactories";
}

} // namespace inexor::entity_system::type_system
