#include "LogicalFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

LogicalFactories::LogicalFactories(ComparisonFactoriesPtr comparison_factories, GateFactoriesPtr gate_factories)
    : LifeCycleComponent(comparison_factories, gate_factories)
{
    this->comparison_factories = std::move(comparison_factories);
    this->gate_factories = std::move(gate_factories);
}

LogicalFactories::~LogicalFactories() = default;

std::string LogicalFactories::get_component_name()
{
    return "LogicalFactories";
}

} // namespace inexor::entity_system::type_system
