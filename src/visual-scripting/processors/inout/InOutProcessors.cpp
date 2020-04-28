#include <visual-scripting/processors/inout/InOutProcessors.hpp>

#include <utility>

namespace inexor::visual_scripting {

InOutProcessors::InOutProcessors(ConsoleProcessorsPtr console_processors, LoggerProcessorsPtr logger_processors)
    : LifeCycleComponent(console_processors, logger_processors)
{
    this->console_processors = std::move(console_processors);
    this->logger_processors = std::move(logger_processors);
}

InOutProcessors::~InOutProcessors() = default;

std::string InOutProcessors::get_component_name()
{
    return "InOutProcessors";
}

} // namespace inexor::visual_scripting
