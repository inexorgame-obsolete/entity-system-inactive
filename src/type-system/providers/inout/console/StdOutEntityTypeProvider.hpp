#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class StdOutEntityTypeProvider
/// @brief Provides an entity type "CONSOLE_STDOUT".
class StdOutEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type CONSOLE_STDOUT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit StdOutEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{CONSOLE_STDOUT, {DataType::STRING, 1 << Feature::INPUT}}}){};

    /// Destructor.
    ~StdOutEntityTypeProvider() override = default;

    /// Defines the name of this entity type
    static constexpr char TYPE_NAME[] = "CONSOLE_STDOUT";

    /// The name of the attribute console_stdout
    static constexpr char CONSOLE_STDOUT[] = "console_stdout";
};

} // namespace inexor::entity_system::type_system
