#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class IntStoreFactory
/// @brief Factory for creating entity instances of type INT_STORE.
class IntStoreFactory : public LifeCycleComponent
{
    public:
    /// @brief Constructs a factory for creating entity instances of type INT_STORE.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    IntStoreFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~IntStoreFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Creates an instance with default values.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an instance with the given name.
    /// @param name ?
    /// @param input_value ?
    /// @param default_value ?
    /// @param output_value ?
    EntityInstancePtrOpt create_instance(const std::string &name, const int &input_value, const int &default_value, const int &output_value);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
