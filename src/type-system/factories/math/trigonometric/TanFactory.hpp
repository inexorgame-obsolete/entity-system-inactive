#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

/// @class TanFactory
/// @brief Factory for creating entity instances of type TAN.
class TanFactory : public LifeCycleComponent
{
    public:
    using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// Constructs a factory for creating entity instances of type TAN.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    TanFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~TanFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Creates an instance with default values.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an instance with the given input value.
    /// @param input The given input value of type float.
    EntityInstancePtrOpt create_instance(float input);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
