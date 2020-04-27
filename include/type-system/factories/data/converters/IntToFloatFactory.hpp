#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class IntToFloatFactory
/// @brief Factory for creating entity instances of type INT_TO_FLOAT.
class IntToFloatFactory : public LifeCycleComponent
{
    public:
    /// @brief Constructs a factory for creating entity instances of type INT_TO_FLOAT.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    explicit IntToFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~IntToFloatFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Creates an INT_TO_FLOAT.
    EntityInstancePtrOpt create_instance();

    /// Creates an INT_TO_FLOAT.
    /// @param name ?
    /// @param int_value ?
    /// @param float_value ?
    EntityInstancePtrOpt create_instance(const std::string &name, const int &int_value, const float &float_value);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
