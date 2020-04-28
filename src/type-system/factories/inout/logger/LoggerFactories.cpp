#include <type-system/factories/inout/logger/LoggerFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

LoggerFactories::LoggerFactories(LoggerFactoryPtr logger_factory)
    : LifeCycleComponent(logger_factory)
{
    this->logger_factory = std::move(logger_factory);
}

LoggerFactories::~LoggerFactories() = default;

std::string LoggerFactories::get_component_name()
{
    return "LoggerFactories";
}

} // namespace inexor::entity_system::type_system
