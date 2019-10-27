#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logical/gates/OrEntityTypeProvider.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

/// @class OrFactory
/// @brief Factory for creating entity instances of type OR.
class OrFactory
{
    public:
    using OrEntityTypeProviderPtr = std::shared_ptr<OrEntityTypeProvider>;
    using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// @brief Constructs a factory for creating entity instances of type OR.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider Provides the entity type OR.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    OrFactory(OrEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~OrFactory();

    /// Initializes the factory.
    void init();

    /// Creates an instance with default values
    EntityInstancePtrOpt create_instance();

    private:
    /// Provides the entity type OR.
    OrEntityTypeProviderPtr entity_type_provider;

    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
