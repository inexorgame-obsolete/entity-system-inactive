#include "InOutProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

InOutProcessors::InOutProcessors(ConsoleProcessorsPtr console_processors, LoggerProcessorsPtr logger_processors)
{
    this->console_processors = std::move(console_processors);
    this->logger_processors = std::move(logger_processors);
}

InOutProcessors::~InOutProcessors() = default;

void InOutProcessors::init()
{
    console_processors->init();
    logger_processors->init();
}

} // namespace inexor::visual_scripting
