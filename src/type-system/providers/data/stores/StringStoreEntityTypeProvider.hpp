#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

using namespace magic_enum::bitwise_operators;

/// @class StringStoreEntityTypeProvider
/// @brief Provides an entity type "STRING_STORE".
class StringStoreEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the STRING_STORE entity type.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit StringStoreEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{STRING_STORE_NAME, {DataType::STRING, Features::OUTPUT}},
                              {STRING_STORE_INPUT_VALUE, {DataType::STRING, Features::INPUT}},
                              {STRING_STORE_DEFAULT_VALUE, {DataType::STRING, Features::INPUT | Features::OUTPUT}},
                              {STRING_STORE_OUTPUT_VALUE, {DataType::STRING, Features::OUTPUT}}}){};

    /// Destructor.
    ~StringStoreEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "STRING_STORE";

    /// The name of the store.
    static constexpr char STRING_STORE_NAME[] = "string_store_name";

    /// The name of the input attribute.
    static constexpr char STRING_STORE_INPUT_VALUE[] = "string_store_input_value";

    /// The name of the default value attribute.
    static constexpr char STRING_STORE_DEFAULT_VALUE[] = "string_store_default_value";

    /// The name of the output value attribute.
    static constexpr char STRING_STORE_OUTPUT_VALUE[] = "string_store_output_value";
};

} // namespace inexor::entity_system::type_system
