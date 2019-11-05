#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/inout/logger/LoggerEntityTypeProvider.hpp"

#include "spdlog/common.h"

namespace inexor::entity_system::type_system {

using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class LoggerFactory
/// @brief Factory for creating entity instances of type LOGGER.
class LoggerFactory
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    LoggerFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~LoggerFactory();

    /// Initializes the factory.
    void init();

    /// Initialization of the loggers.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an instance and sets the given name.
    /// @param logger_name The name of the logger instance.
    EntityInstancePtrOpt create_instance(const std::string& logger_name);

    /// @brief Creates an instance and sets the given name.
    /// @param logger_name The name of the logger instance.
    /// @param log_level The level of the logger instance.
    EntityInstancePtrOpt create_instance(const std::string& logger_name, spdlog::level::level_enum log_level);

    /// @brief Creates multiple instances.
    /// @param count The number of logger instances to create.
    std::vector<EntityInstancePtr> create_instances(int count);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
