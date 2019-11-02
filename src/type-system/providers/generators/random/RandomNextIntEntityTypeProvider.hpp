#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class RandomNextIntEntityTypeProvider
/// @brief Provides an entity type "RANDOM_NEXT_INT".
class RandomNextIntEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type RANDOM_NEXT_INT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit RandomNextIntEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{RANDOM_NEXT_INT_ON_ACTIVATION, {DataType::BOOL, Features::INPUT}},
                              {RANDOM_NEXT_INT_MIN, {DataType::INT, Features::INPUT}},
                              {RANDOM_NEXT_INT_MAX, {DataType::INT, Features::INPUT}},
                              {RANDOM_NEXT_INT_VALUE, {DataType::INT, Features::OUTPUT}}}){};

    /// Destructor.
    ~RandomNextIntEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "RANDOM_NEXT_INT";

    /// The name of the attribute random_next_int_on_activation.
    static constexpr char RANDOM_NEXT_INT_ON_ACTIVATION[] = "random_next_int_on_activation";

    /// The name of the attribute random_next_int_min.
    static constexpr char RANDOM_NEXT_INT_MIN[] = "random_next_int_min";

    /// The name of the attribute random_next_int_max.
    static constexpr char RANDOM_NEXT_INT_MAX[] = "random_next_int_max";

    /// The name of the attribute random_next_int_value.
    static constexpr char RANDOM_NEXT_INT_VALUE[] = "random_next_int_value";
};

} // namespace inexor::entity_system::type_system
