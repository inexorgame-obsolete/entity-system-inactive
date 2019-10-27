#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class BoolConstantEntityTypeProvider
/// @brief Provides an entity type "BOOL_CONSTANT" which is a pure bool constant variable.
class BoolConstantEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the BOOL_CONSTANT entity type.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit BoolConstantEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{BOOL_CONSTANT_NAME, {DataType::STRING, 1 << Feature::OUTPUT}}, {BOOL_CONSTANT_VALUE, {DataType::BOOL, 1 << Feature::OUTPUT}}}){};

    /// Destructor.
    ~BoolConstantEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "BOOL_CONSTANT";

    /// The name of the output attribute bool_constant_name.
    static constexpr char BOOL_CONSTANT_NAME[] = "bool_constant_name";

    /// The name of the output attribute bool_constant_value.
    static constexpr char BOOL_CONSTANT_VALUE[] = "bool_constant_value";
};

} // namespace inexor::entity_system::type_system
