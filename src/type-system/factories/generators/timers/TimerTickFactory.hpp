#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class TimerTickFactory
/// @brief Factory for creating entity instances of type TIMER_TICK.
class TimerTickFactory
{
    public:
    /// @brief Constructs a factory for creating entity instances of type TIMER_TICK.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    TimerTickFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~TimerTickFactory();

    /// Initializes the factory.
    void init();

    /// Creates a counter with the default values: millis = 1000.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an counter with the specified
    /// @param millis ?
    EntityInstancePtrOpt create_instance(int millis);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
