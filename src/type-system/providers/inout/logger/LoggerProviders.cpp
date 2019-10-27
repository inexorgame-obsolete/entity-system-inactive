#include "LoggerProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

LoggerProviders::LoggerProviders(LoggerEntityTypeProviderPtr logger_entity_type_provider)
{
    this->logger_entity_type_provider = std::move(logger_entity_type_provider);
}

LoggerProviders::~LoggerProviders() = default;

void LoggerProviders::init()
{
}

} // namespace inexor::entity_system::type_system
