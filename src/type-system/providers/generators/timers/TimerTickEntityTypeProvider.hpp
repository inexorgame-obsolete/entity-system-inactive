#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class TimerTickEntityTypeProvider
/// @brief Provides an entity type "TIMER_TICK".
class TimerTickEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type TIMER_TICK.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit TimerTickEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME, {{TIMER_TICK_MILLIS, {DataType::INT, Features::INPUT}}, {TIMER_TICK_VALUE, {DataType::BOOL, Features::OUTPUT}}}){};

    /// Destructor.
    ~TimerTickEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "TIMER_TICK";

    /// The name of the attribute timer_tick_millis.
    static constexpr char TIMER_TICK_MILLIS[] = "timer_tick_millis";

    /// The name of the attribute timer_tick_value.
    static constexpr char TIMER_TICK_VALUE[] = "timer_tick_value";
};

} // namespace inexor::entity_system::type_system
