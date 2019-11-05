#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class StringStoreFactory
/// @brief Factory for creating entity instances of type STRING_STORE.
class StringStoreFactory
{
    public:
    /// @brief Constructs a factory for creating entity instances of type STRING_STORE.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    StringStoreFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~StringStoreFactory();

    /// Initializes the factory.
    void init();

    /// Creates an instance with default values.
    EntityInstancePtrOpt create_instance();

    /// @brief Creates an instance with the given name.
    /// @param name ?
    /// @param input_value ?
    /// @param default_value ?
    /// @param output_value ?
    EntityInstancePtrOpt create_instance(const std::string &name, const std::string &input_value, const std::string &default_value, const std::string &output_value);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
