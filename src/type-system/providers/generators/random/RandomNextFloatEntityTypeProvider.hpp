#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class RandomNextFloatEntityTypeProvider
/// @brief Provides an entity type "RANDOM_NEXT_FLOAT".
class RandomNextFloatEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type RANDOM_NEXT_FLOAT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit RandomNextFloatEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{RANDOM_NEXT_FLOAT_ON_ACTIVATION, {DataType::BOOL, Features::INPUT}},
                              {RANDOM_NEXT_FLOAT_MIN, {DataType::FLOAT, Features::INPUT}},
                              {RANDOM_NEXT_FLOAT_MAX, {DataType::FLOAT, Features::INPUT}},
                              {RANDOM_NEXT_FLOAT_VALUE, {DataType::FLOAT, Features::OUTPUT}}}){};

    /// Destructor.
    ~RandomNextFloatEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "RANDOM_NEXT_FLOAT";

    /// The name of the attribute random_next_float_on_activation.
    static constexpr char RANDOM_NEXT_FLOAT_ON_ACTIVATION[] = "random_next_float_on_activation";

    /// The name of the attribute random_next_float_min.
    static constexpr char RANDOM_NEXT_FLOAT_MIN[] = "random_next_float_min";

    /// The name of the attribute random_next_float_max.
    static constexpr char RANDOM_NEXT_FLOAT_MAX[] = "random_next_float_max";

    /// The name of the attribute random_next_float_value.
    static constexpr char RANDOM_NEXT_FLOAT_VALUE[] = "random_next_float_value";
};

} // namespace inexor::entity_system::type_system
