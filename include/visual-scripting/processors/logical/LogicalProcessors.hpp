#pragma once

#include "visual-scripting/processors/logical/comparison/ComparisonProcessors.hpp"
#include "visual-scripting/processors/logical/gates/GateProcessors.hpp"

namespace inexor::visual_scripting {

using ComparisonProcessorsPtr = std::shared_ptr<ComparisonProcessors>;
using GateProcessorsPtr = std::shared_ptr<GateProcessors>;

/// @class LogicalProcessors
/// @brief Provides processors.
class LogicalProcessors : public LifeCycleComponent
{
    public:
    /// @brief Constructs the processors for logical operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param comparison_processors The processors for comparison operations.
    /// @param gate_processors The processors logical gates.
    LogicalProcessors(ComparisonProcessorsPtr comparison_processors, GateProcessorsPtr gate_processors);

    /// Destructor.
    ~LogicalProcessors();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The processors for comparison operations.
    ComparisonProcessorsPtr comparison_processors;

    /// The processors logical gates.
    GateProcessorsPtr gate_processors;
};

} // namespace inexor::visual_scripting
