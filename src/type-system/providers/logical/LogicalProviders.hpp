#pragma once

#include "type-system/providers/logical/comparison/ComparisonProviders.hpp"
#include "type-system/providers/logical/gates/GateProviders.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using ComparisonProvidersPtr = std::shared_ptr<ComparisonProviders>;
using GateProvidersPtr = std::shared_ptr<GateProviders>;

/// @class LogicalProviders
/// @brief The entity type providers for logical operations.
class LogicalProviders
{
    public:
    /// @brief Constructs the entity type providers for logical operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param comparison_providers The providers for the comparison operations.
    /// @param gate_providers The providers for the logical gates.
    LogicalProviders(ComparisonProvidersPtr comparison_providers, GateProvidersPtr gate_providers);

    /// Destructor.
    ~LogicalProviders();

    /// Initializes the providers for logical operations.
    void init();

    private:
    /// The providers for the comparison operations.
    ComparisonProvidersPtr comparison_providers;

    /// The providers for the logical gates.
    GateProvidersPtr gate_providers;
};

} // namespace inexor::entity_system::type_system
