#include "ConsoleProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

ConsoleProcessors::ConsoleProcessors(StdInProcessorPtr stdin_processor, StdOutProcessorPtr stdout_processor, StdErrProcessorPtr stderr_processor)
    : LifeCycleComponent(stdin_processor, stdout_processor, stderr_processor)
{
    this->stdin_processor = std::move(stdin_processor);
    this->stdout_processor = std::move(stdout_processor);
    this->stderr_processor = std::move(stderr_processor);
}

ConsoleProcessors::~ConsoleProcessors() = default;

std::string ConsoleProcessors::get_component_name()
{
    return "ConsoleProcessors";
}

} // namespace inexor::visual_scripting
