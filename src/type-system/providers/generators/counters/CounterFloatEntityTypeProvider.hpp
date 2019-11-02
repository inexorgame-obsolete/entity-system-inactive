#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class CounterFloatEntityTypeProvider
/// @brief Provides an entity type "COUNTER_FLOAT".
class CounterFloatEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type COUNTER_FLOAT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit CounterFloatEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{COUNTER_FLOAT_MILLIS, {DataType::INT, Features::INPUT}},
                              {COUNTER_FLOAT_STEP, {DataType::FLOAT, Features::INPUT}},
                              {COUNTER_FLOAT_RESET, {DataType::BOOL, Features::INPUT}},
                              {COUNTER_FLOAT_COUNT, {DataType::FLOAT, Features::OUTPUT}}}){};

    /// Destructor.
    ~CounterFloatEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "COUNTER_FLOAT";

    /// The name of the attribute counter_float_millis.
    static constexpr char COUNTER_FLOAT_MILLIS[] = "counter_float_millis";

    /// The name of the attribute counter_float_step.
    static constexpr char COUNTER_FLOAT_STEP[] = "counter_float_step";

    /// The name of the attribute counter_float_reset.
    static constexpr char COUNTER_FLOAT_RESET[] = "counter_float_reset";

    /// The name of the attribute counter_float_count.
    static constexpr char COUNTER_FLOAT_COUNT[] = "counter_float_count";
};

} // namespace inexor::entity_system::type_system
