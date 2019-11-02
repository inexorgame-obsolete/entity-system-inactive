#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

using namespace magic_enum::bitwise_operators;

/// @class LoggerEntityTypeProvider
/// Provides an entity type "LOGGER". The LOGGER logs.
class LoggerEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the LOGGER entity type.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit LoggerEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{LOGGER_NAME, {DataType::STRING, Features::OUTPUT}}, {LOG_LEVEL, {DataType::INT, Features::INPUT | Features::OUTPUT}}, {LOG_MESSAGE, {DataType::STRING, Features::INPUT}}}){};

    /// Destructor.
    ~LoggerEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "LOGGER";

    /// The name of the attribute logger_name.
    static constexpr char LOGGER_NAME[] = "logger_name";

    /// The name of the attribute log_level.
    static constexpr char LOG_LEVEL[] = "log_level";

    /// The name of the attribute log_message.
    static constexpr char LOG_MESSAGE[] = "log_message";
};

} // namespace inexor::entity_system::type_system
