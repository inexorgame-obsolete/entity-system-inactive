#pragma once

#include "type-system/factories/logical/comparison/ComparisonFactories.hpp"
#include "type-system/factories/logical/gates/GateFactories.hpp"

namespace inexor::entity_system::type_system {

using ComparisonFactoriesPtr = std::shared_ptr<ComparisonFactories>;
using GateFactoriesPtr = std::shared_ptr<GateFactories>;

/// @class LogicalFactories
/// @brief The factories for logical operations.
class LogicalFactories
{
    public:
    /// @brief Constructs the factories for logical operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param comparison_factories The factories for comparison operations.
    /// @param gate_factories The factories for logical gates.
    LogicalFactories(ComparisonFactoriesPtr comparison_factories, GateFactoriesPtr gate_factories);

    /// Destructor.
    ~LogicalFactories();

    /// Initializes the factories for logical operations.
    void init();

    private:
    /// The factories for comparison operations.
    ComparisonFactoriesPtr comparison_factories;

    /// The factories for logical gates.
    GateFactoriesPtr gate_factories;
};

} // namespace inexor::entity_system::type_system
