#include "LoggerProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

LoggerProcessors::LoggerProcessors(LoggerProcessorPtr logger_processor)
{
    this->logger_processor = std::move(logger_processor);
}

LoggerProcessors::~LoggerProcessors() = default;

void LoggerProcessors::init()
{
    logger_processor->init();
}

} // namespace inexor::visual_scripting
