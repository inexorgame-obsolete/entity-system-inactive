#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

#include <memory>
#include <optional>

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class BoolConstantFactory
/// @brief Factory for creating entity instances of type BOOL_CONSTANT.
class BoolConstantFactory
{
    public:
    /// @brief Constructs a factory for creating entity instances of type BOOL_CONSTANT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    BoolConstantFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~BoolConstantFactory();

    /// Initializes the factory.
    void init();

    /// Creates an instance with default values.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an BOOL_CONSTANT with the given constant name and the given value.
    /// @param name ?
    /// @param value ?
    EntityInstancePtrOpt create_instance(const std::string &name, const bool &value);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
