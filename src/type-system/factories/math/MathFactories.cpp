#include <type-system/factories/math/MathFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

MathFactories::MathFactories(ArithmeticFactoriesPtr arithmetic_factories, TrigonometricFactoriesPtr trigonometric_factories)
    : LifeCycleComponent(arithmetic_factories, trigonometric_factories)
{
    this->arithmetic_factories = std::move(arithmetic_factories);
    this->trigonometric_factories = std::move(trigonometric_factories);
}

MathFactories::~MathFactories() = default;

std::string MathFactories::get_component_name()
{
    return "MathFactories";
}

} // namespace inexor::entity_system::type_system
