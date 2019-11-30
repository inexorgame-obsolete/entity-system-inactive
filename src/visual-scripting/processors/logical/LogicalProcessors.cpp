#include "LogicalProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

LogicalProcessors::LogicalProcessors(ComparisonProcessorsPtr comparison_processors, GateProcessorsPtr gate_processors)
    : LifeCycleComponent(comparison_processors, gate_processors)
{
    this->comparison_processors = std::move(comparison_processors);
    this->gate_processors = std::move(gate_processors);
}

LogicalProcessors::~LogicalProcessors() = default;

std::string LogicalProcessors::get_component_name()
{
    return "LogicalProcessors";
}

} // namespace inexor::visual_scripting
