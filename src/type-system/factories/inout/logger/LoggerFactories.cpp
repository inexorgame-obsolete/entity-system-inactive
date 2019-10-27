#include "LoggerFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

LoggerFactories::LoggerFactories(LoggerFactoryPtr logger_factory)
{
    this->logger_factory = std::move(logger_factory);
}

LoggerFactories::~LoggerFactories() = default;

void LoggerFactories::init()
{
    logger_factory->init();
}

} // namespace inexor::entity_system::type_system
