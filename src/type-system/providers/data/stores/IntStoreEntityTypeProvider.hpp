#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class IntStoreEntityTypeProvider
/// @brief Provides an entity type "INT_STORE".
class IntStoreEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the INT_STORE entity type.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit IntStoreEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{INT_STORE_NAME, {DataType::STRING, 1 << Feature::OUTPUT}},
                              {INT_STORE_INPUT_VALUE, {DataType::INT, 1 << Feature::INPUT}},
                              {INT_STORE_DEFAULT_VALUE, {DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT}},
                              {INT_STORE_OUTPUT_VALUE, {DataType::INT, 1 << Feature::OUTPUT}}}){};

    /// Destructor.
    ~IntStoreEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "INT_STORE";

    /// The name of the store.
    static constexpr char INT_STORE_NAME[] = "int_store_name";

    /// The name of the input attribute.
    static constexpr char INT_STORE_INPUT_VALUE[] = "int_store_input_value";

    /// The name of the default value attribute.
    static constexpr char INT_STORE_DEFAULT_VALUE[] = "int_store_default_value";

    /// The name of the output value attribute.
    static constexpr char INT_STORE_OUTPUT_VALUE[] = "int_store_output_value";
};

} // namespace inexor::entity_system::type_system
