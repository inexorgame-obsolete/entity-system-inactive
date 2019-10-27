#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/inout/keyboard/GlobalKeyEntityTypeProvider.hpp"

#include "spdlog/common.h"

namespace inexor::entity_system::type_system {

using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
using GlobalKeyEntityTypeProviderPtr = std::shared_ptr<GlobalKeyEntityTypeProvider>;

/// @class GlobalKeyFactory
/// @brief Factory for creating entity instances of type GLOBAL_KEY.
class GlobalKeyFactory
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider Provides the entity type GLOBAL_KEY.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    GlobalKeyFactory(GlobalKeyEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~GlobalKeyFactory();

    /// Initializes the factory.
    void init();

    /// @brief Creates an instance and sets the given name.
    /// @param key The key code.
    EntityInstancePtrOpt create_instance(const int &key);

    private:
    /// Provides the entity type GLOBAL_KEY.
    GlobalKeyEntityTypeProviderPtr entity_type_provider;

    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
