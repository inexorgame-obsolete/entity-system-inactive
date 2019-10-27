#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logical/comparison/GreaterThanIntEntityTypeProvider.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

/// @class GreaterThanIntFactory
/// @brief Factory for creating entity instances of type GREATER_THAN_INT.
class GreaterThanIntFactory
{
    public:
    using GreaterThanIntEntityTypeProviderPtr = std::shared_ptr<GreaterThanIntEntityTypeProvider>;
    using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// @brief Constructs a factory for creating entity instances of type GREATER_THAN_INT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider Provides the entity type GREATER_THAN_INT.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    GreaterThanIntFactory(GreaterThanIntEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~GreaterThanIntFactory();

    /// Initializes the factory.
    void init();

    /// Creates an instance with default values.
    EntityInstancePtrOpt create_instance();

    private:
    /// Provides the entity type GREATER_THAN_INT.
    GreaterThanIntEntityTypeProviderPtr entity_type_provider;

    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
