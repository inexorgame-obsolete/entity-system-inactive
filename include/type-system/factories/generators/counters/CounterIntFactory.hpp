#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class Documentation of
/// @brief Factory for creating entity instances of type COUNTER_INT.
class CounterIntFactory : public LifeCycleComponent
{
    public:
    /// Constructs a factory for creating entity instances of type COUNTER_INT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    CounterIntFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~CounterIntFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Creates a counter with the default values: millis = 1000, step = 1, start_value = 0.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an counter with the specified
    /// @param millis ?
    /// @param step ?
    EntityInstancePtrOpt create_instance(int millis, int step);

    /// @brief Creates an counter with the specified
    /// @param millis ?
    /// @param step ?
    /// @param start_value ?
    EntityInstancePtrOpt create_instance(int millis, int step, int start_value);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
