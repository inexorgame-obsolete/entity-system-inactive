#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class CosEntityTypeProvider
/// @brief Provides an entity type "COS": cos_value = cos(cos_input).
class CosEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type COS.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit CosEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{COS_INPUT, {DataType::FLOAT, 1 << Feature::INPUT}}, {COS_VALUE, {DataType::FLOAT, 1 << Feature::OUTPUT}}}){};

    /// Destructor.
    ~CosEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "COS";

    /// The name for the attribute cos_input.
    static constexpr char COS_INPUT[] = "cos_input";

    /// The name for the attribute cos_value.
    static constexpr char COS_VALUE[] = "cos_value";
};

} // namespace inexor::entity_system::type_system
