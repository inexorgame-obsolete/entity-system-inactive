#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

using namespace magic_enum::bitwise_operators;

/// @class FloatConstantEntityTypeProvider
/// @brief Provides an entity type "FLOAT_CONSTANT" which is a pure float constant variable.
class FloatConstantEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the FLOAT_CONSTANT entity type.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit FloatConstantEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{FLOAT_CONSTANT_NAME, {DataType::STRING, Features::OUTPUT}}, {FLOAT_CONSTANT_VALUE, {DataType::FLOAT, Features::INPUT | Features::OUTPUT}}}){};

    /// Destructor.
    ~FloatConstantEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "FLOAT_CONSTANT";

    /// The name of the output attribute float_constant_name.
    static constexpr char FLOAT_CONSTANT_NAME[] = "float_constant_name";

    /// The name of the output attribute float_constant_value.
    static constexpr char FLOAT_CONSTANT_VALUE[] = "float_constant_value";
};

} // namespace inexor::entity_system::type_system
