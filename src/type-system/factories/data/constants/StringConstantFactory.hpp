#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

#include <memory>
#include <optional>

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class StringConstantFactory
/// @brief Factory for creating entity instances of type STRING_CONSTANT.
class StringConstantFactory
{
    public:
    /// @brief Constructs a factory for creating entity instances of type STRING_CONSTANT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    StringConstantFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~StringConstantFactory();

    /// Initializes the factory.
    void init();

    /// Creates an instance with default values.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an STRING_CONSTANT with the given constant name.
    /// @param name The name of the string constant.
    EntityInstancePtrOpt create_instance(const std::string &name);

    /// @brief Creates an STRING_CONSTANT with the given constant name and the given value.
    /// @param name The name of the string constant.
    /// @param value The initial value of the string constant.
    EntityInstancePtrOpt create_instance(const std::string &name, const std::string &value);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
