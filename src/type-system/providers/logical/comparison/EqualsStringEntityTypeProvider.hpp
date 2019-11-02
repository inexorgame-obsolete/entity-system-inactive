#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class EqualsStringEntityTypeProvider
/// @brief Provides an entity type "EQUALS_STRING".
class EqualsStringEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type EQUALS_STRING.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit EqualsStringEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{EQUALS_STRING_INPUT_1, {DataType::STRING, Features::INPUT}}, {EQUALS_STRING_INPUT_2, {DataType::STRING, Features::INPUT}}, {EQUALS_STRING_RESULT, {DataType::BOOL, Features::OUTPUT}}}){};

    /// Destructor.
    ~EqualsStringEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "EQUALS_STRING";

    /// The name of the attribute equals_string_input_1.
    static constexpr char EQUALS_STRING_INPUT_1[] = "equals_string_input_1";

    /// The name of the attribute equals_string_input_1.
    static constexpr char EQUALS_STRING_INPUT_2[] = "equals_string_input_2";

    /// The name of the attribute equals_string_result.
    static constexpr char EQUALS_STRING_RESULT[] = "equals_string_result";
};

} // namespace inexor::entity_system::type_system
