#include "MathFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

MathFactories::MathFactories(ArithmeticFactoriesPtr arithmetic_factories)
{
    this->arithmetic_factories = std::move(arithmetic_factories);
}

MathFactories::~MathFactories() = default;

void MathFactories::init()
{
    arithmetic_factories->init();
}

} // namespace inexor::entity_system::type_system
