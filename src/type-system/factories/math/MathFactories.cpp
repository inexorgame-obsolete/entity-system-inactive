#include "MathFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

MathFactories::MathFactories(ArithmeticFactoriesPtr arithmetic_factories, TrigonometricFactoriesPtr trigonometric_factories)
{
    this->arithmetic_factories = std::move(arithmetic_factories);
    this->trigonometric_factories = std::move(trigonometric_factories);
}

MathFactories::~MathFactories() = default;

void MathFactories::init()
{
    arithmetic_factories->init();
    trigonometric_factories->init();
}

} // namespace inexor::entity_system::type_system
