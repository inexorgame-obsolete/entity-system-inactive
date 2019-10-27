#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class EqualsBoolEntityTypeProvider
/// @brief Provides an entity type "EQUALS_BOOL".
class EqualsBoolEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// Constructs the specialized provider for the entity type EQUALS_BOOL.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit EqualsBoolEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{EQUALS_BOOL_INPUT_1, {DataType::BOOL, 1 << Feature::INPUT}}, {EQUALS_BOOL_INPUT_2, {DataType::BOOL, 1 << Feature::INPUT}}, {EQUALS_BOOL_RESULT, {DataType::BOOL, 1 << Feature::OUTPUT}}}){};

    /// Destructor.
    ~EqualsBoolEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "EQUALS_BOOL";

    /// The name of the attribute equals_bool_input_1.
    static constexpr char EQUALS_BOOL_INPUT_1[] = "equals_bool_input_1";

    /// The name of the attribute equals_bool_input_1.
    static constexpr char EQUALS_BOOL_INPUT_2[] = "equals_bool_input_2";

    /// The name of the attribute equals_bool_result.
    static constexpr char EQUALS_BOOL_RESULT[] = "equals_bool_result";
};

} // namespace inexor::entity_system::type_system
