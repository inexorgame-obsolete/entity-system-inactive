#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

#include <memory>
#include <optional>

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class FloatConstantFactory
/// @brief Factory for creating entity instances of type FLOAT_CONSTANT.
class FloatConstantFactory : public LifeCycleComponent
{
    public:
    /// @brief Constructs a factory for creating entity instances of type FLOAT_CONSTANT.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    FloatConstantFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~FloatConstantFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Creates an instance with default values.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an FLOAT_CONSTANT with the given constant name and the given value.
    /// @param name ?
    /// @param value ?
    EntityInstancePtrOpt create_instance(const std::string &name, const float &value);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
