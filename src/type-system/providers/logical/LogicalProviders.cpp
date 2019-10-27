#include "LogicalProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

LogicalProviders::LogicalProviders(ComparisonProvidersPtr comparison_providers, GateProvidersPtr gate_providers)
{
    this->comparison_providers = std::move(comparison_providers);
    this->gate_providers = std::move(gate_providers);
}

LogicalProviders::~LogicalProviders() = default;

void LogicalProviders::init()
{
    comparison_providers->init();
    gate_providers->init();
}

} // namespace inexor::entity_system::type_system
