#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logical/gates/NandEntityTypeProvider.hpp"

namespace inexor::entity_system::type_system {

using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

/// @class NandFactory
/// @brief Factory for creating entity instances of type NAND.
class NandFactory
{
    public:
    using NandEntityTypeProviderPtr = std::shared_ptr<NandEntityTypeProvider>;
    using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// @brief Constructs a factory for creating entity instances of type NAND.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider Provides the entity type NAND.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    NandFactory(NandEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~NandFactory();

    /// Initializes the factory.
    void init();

    /// Creates an instance with default values
    EntityInstancePtrOpt create_instance();

    private:
    /// Provides the entity type NAND.
    NandEntityTypeProviderPtr entity_type_provider;

    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
