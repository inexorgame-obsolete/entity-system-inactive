#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class GreaterThanFloatEntityTypeProvider
/// @brief Provides an entity type "GREATER_THAN_FLOAT".
class GreaterThanFloatEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type GREATER_THAN_FLOAT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit GreaterThanFloatEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(
              std::move(entity_type_builder_manager), TYPE_NAME,
              {{GREATER_THAN_FLOAT_INPUT_1, {DataType::FLOAT, Features::INPUT}}, {GREATER_THAN_FLOAT_INPUT_2, {DataType::FLOAT, Features::INPUT}}, {GREATER_THAN_FLOAT_RESULT, {DataType::BOOL, Features::OUTPUT}}}){};

    /// Destructor.
    ~GreaterThanFloatEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "GREATER_THAN_FLOAT";

    /// The name of the attribute greater_than_float_input_1.
    static constexpr char GREATER_THAN_FLOAT_INPUT_1[] = "greater_than_float_input_1";

    /// The name of the attribute greater_than_float_input_1.
    static constexpr char GREATER_THAN_FLOAT_INPUT_2[] = "greater_than_float_input_2";

    /// The name of the attribute greater_than_float_result.
    static constexpr char GREATER_THAN_FLOAT_RESULT[] = "greater_than_float_result";
};

} // namespace inexor::entity_system::type_system
