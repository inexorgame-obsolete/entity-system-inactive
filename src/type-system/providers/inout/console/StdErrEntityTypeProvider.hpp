#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class StdErrEntityTypeProvider
/// @brief Provides an entity type "CONSOLE_STDERR".
class StdErrEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type CONSOLE_STDERR.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit StdErrEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{CONSOLE_STDERR, {DataType::STRING, 1 << Feature::INPUT}}}){};

    /// Destructor.
    ~StdErrEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "CONSOLE_STDERR";

    /// The name of the attribute console_stderr.
    static constexpr char CONSOLE_STDERR[] = "console_stderr";
};

} // namespace inexor::entity_system::type_system
