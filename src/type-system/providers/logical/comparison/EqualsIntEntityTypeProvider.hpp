#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class EqualsIntEntityTypeProvider
/// @brief Provides an entity type "EQUALS_INT".
class EqualsIntEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type EQUALS_INT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit EqualsIntEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{EQUALS_INT_INPUT_1, {DataType::INT, Features::INPUT}}, {EQUALS_INT_INPUT_2, {DataType::INT, Features::INPUT}}, {EQUALS_INT_RESULT, {DataType::BOOL, Features::OUTPUT}}}){};

    /// Destructor.
    ~EqualsIntEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "EQUALS_INT";

    /// The name of the attribute equals_int_input_1.
    static constexpr char EQUALS_INT_INPUT_1[] = "equals_int_input_1";

    /// The name of the attribute equals_int_input_1.
    static constexpr char EQUALS_INT_INPUT_2[] = "equals_int_input_2";

    /// The name of the attribute equals_int_result.
    static constexpr char EQUALS_INT_RESULT[] = "equals_int_result";
};

} // namespace inexor::entity_system::type_system
