#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

using namespace magic_enum::bitwise_operators;

/// @class IntConstantEntityTypeProvider
/// @brief Provides an entity type "INT_CONSTANT" which is a pure int constant variable.
class IntConstantEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the INT_CONSTANT entity type.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit IntConstantEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{INT_CONSTANT_NAME, {DataType::STRING, Features::OUTPUT}}, {INT_CONSTANT_VALUE, {DataType::INT, Features::INPUT | Features::OUTPUT}}}){};

    /// Destructor.
    ~IntConstantEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "INT_CONSTANT";

    /// The name of the output attribute int_constant_name.
    static constexpr char INT_CONSTANT_NAME[] = "int_constant_name";

    /// The name of the output attribute int_constant_value.
    static constexpr char INT_CONSTANT_VALUE[] = "int_constant_value";
};

} // namespace inexor::entity_system::type_system
