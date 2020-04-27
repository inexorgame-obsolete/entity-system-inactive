#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

#include <memory>
#include <optional>

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class IntConstantFactory
/// @brief Factory for creating entity instances of type INT_CONSTANT.
class IntConstantFactory : public LifeCycleComponent
{
    public:
    /// @brief Constructs a factory for creating entity instances of type INT_CONSTANT.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    IntConstantFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~IntConstantFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Creates an instance with default values.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an INT_CONSTANT with the given constant name and the given value.
    /// @param name ?
    /// @param value ?
    EntityInstancePtrOpt create_instance(const std::string &name, const int &value);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
