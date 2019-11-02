#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class StringConstantEntityTypeProvider
/// Provides an entity type "STRING_CONSTANT" which is a pure string constant variable.
class StringConstantEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the STRING_CONSTANT entity type
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit StringConstantEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{STRING_CONSTANT_NAME, {DataType::STRING, Features::OUTPUT}}, {STRING_CONSTANT_VALUE, {DataType::STRING, Features::OUTPUT}}}){};

    /// Destructor.
    ~StringConstantEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "STRING_CONSTANT";

    /// The name of the output attribute string_constant_name.
    static constexpr char STRING_CONSTANT_NAME[] = "string_constant_name";

    /// The name of the output attribute string_constant_value.
    static constexpr char STRING_CONSTANT_VALUE[] = "string_constant_value";
};

} // namespace inexor::entity_system::type_system
