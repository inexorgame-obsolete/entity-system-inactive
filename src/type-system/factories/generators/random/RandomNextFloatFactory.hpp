#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class RandomNextFloatFactory
/// @brief Factory for creating entity instances of type RANDOM_NEXT_FLOAT.
class RandomNextFloatFactory
{
    public:
    /// @brief Constructs a factory for creating entity instances of type RANDOM_NEXT_FLOAT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    RandomNextFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~RandomNextFloatFactory();

    /// Initializes the factory.
    void init();

    /// Creates a counter with the default values: millis = 1000, step = 1.0f, start_value = 0.0f.
    EntityInstancePtrOpt create_instance();

    /// Creates an counter with the specified.
    EntityInstancePtrOpt create_instance(float min, float max);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
