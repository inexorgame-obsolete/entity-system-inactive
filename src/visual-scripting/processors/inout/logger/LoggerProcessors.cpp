#include <visual-scripting/processors/inout/logger/LoggerProcessors.hpp>

#include <utility>

namespace inexor::visual_scripting {

LoggerProcessors::LoggerProcessors(LoggerProcessorPtr logger_processor)
    : LifeCycleComponent(logger_processor)
{
    this->logger_processor = std::move(logger_processor);
}

LoggerProcessors::~LoggerProcessors() = default;

std::string LoggerProcessors::get_component_name()
{
    return "LoggerProcessors";
}

} // namespace inexor::visual_scripting
