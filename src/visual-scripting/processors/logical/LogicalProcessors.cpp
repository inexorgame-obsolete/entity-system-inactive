#include "LogicalProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

LogicalProcessors::LogicalProcessors(ComparisonProcessorsPtr comparison_processors, GateProcessorsPtr gate_processors)
{
    this->comparison_processors = std::move(comparison_processors);
    this->gate_processors = std::move(gate_processors);
}

LogicalProcessors::~LogicalProcessors() = default;

void LogicalProcessors::init()
{
    this->comparison_processors->init();
    this->gate_processors->init();
}

} // namespace inexor::visual_scripting
