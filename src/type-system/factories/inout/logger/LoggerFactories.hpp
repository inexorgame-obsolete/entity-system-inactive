#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/inout/logger/LoggerFactory.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using LoggerFactoryPtr = std::shared_ptr<LoggerFactory>;

/// @class LoggerFactories
/// @brief The logger factories.
class LoggerFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the logger factories.
    /// @note The dependencies of this class will be injected automatically.
    /// @param logger_factory Factory for creating entity instances of type LOGGER.
    explicit LoggerFactories(LoggerFactoryPtr logger_factory);

    /// Destructor.
    ~LoggerFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Factory for creating entity instances of type LOGGER.
    LoggerFactoryPtr logger_factory;
};

} // namespace inexor::entity_system::type_system
