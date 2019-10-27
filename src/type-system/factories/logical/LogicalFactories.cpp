#include "LogicalFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

LogicalFactories::LogicalFactories(ComparisonFactoriesPtr comparison_factories, GateFactoriesPtr gate_factories)
{
    this->comparison_factories = std::move(comparison_factories);
    this->gate_factories = std::move(gate_factories);
}

LogicalFactories::~LogicalFactories() = default;

void LogicalFactories::init()
{
    comparison_factories->init();
    gate_factories->init();
}

} // namespace inexor::entity_system::type_system
