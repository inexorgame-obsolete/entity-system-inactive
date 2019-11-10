#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/logical/comparison/ComparisonFactories.hpp"
#include "type-system/factories/logical/gates/GateFactories.hpp"

namespace inexor::entity_system::type_system {

using ComparisonFactoriesPtr = std::shared_ptr<ComparisonFactories>;
using GateFactoriesPtr = std::shared_ptr<GateFactories>;

/// @class LogicalFactories
/// @brief The factories for logical operations.
class LogicalFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the factories for logical operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param comparison_factories The factories for comparison operations.
    /// @param gate_factories The factories for logical gates.
    LogicalFactories(ComparisonFactoriesPtr comparison_factories, GateFactoriesPtr gate_factories);

    /// Destructor.
    ~LogicalFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The factories for comparison operations.
    ComparisonFactoriesPtr comparison_factories;

    /// The factories for logical gates.
    GateFactoriesPtr gate_factories;
};

} // namespace inexor::entity_system::type_system
