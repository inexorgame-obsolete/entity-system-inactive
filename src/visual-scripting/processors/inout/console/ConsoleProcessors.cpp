#include "ConsoleProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

ConsoleProcessors::ConsoleProcessors(StdInProcessorPtr stdin_processor, StdOutProcessorPtr stdout_processor, StdErrProcessorPtr stderr_processor)
{
    this->stdin_processor = std::move(stdin_processor);
    this->stdout_processor = std::move(stdout_processor);
    this->stderr_processor = std::move(stderr_processor);
}

ConsoleProcessors::~ConsoleProcessors() = default;

void ConsoleProcessors::init()
{
    stdin_processor->init();
    stdout_processor->init();
    stderr_processor->init();
}

} // namespace inexor::visual_scripting
