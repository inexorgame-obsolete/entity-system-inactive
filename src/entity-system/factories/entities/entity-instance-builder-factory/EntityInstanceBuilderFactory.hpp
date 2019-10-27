#pragma once

#include "entity-system/builders/entities/entity-instance-builder/EntityInstanceBuilder.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"

namespace inexor::entity_system {

/// These using instructions help to shorten the following code.
using EntityInstanceBuilderPtr = std::shared_ptr<EntityInstanceBuilder>;
using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;

/// @class EntityInstanceBuilderFactory
/// @brief A factory for getting a builder for creating entity instances.
/// @note For more information on the builder software pattern see
/// https://en.wikipedia.org/wiki/Factory_method_pattern
/// https://en.wikipedia.org/wiki/Builder_pattern
class EntityInstanceBuilderFactory
{
    public:
    /// @brief Constructor.
    /// @param entity_instance_manager A shared pointer entity instance manager.
    /// @param entity_type_manager A shared pointer to the entity type manager.
    EntityInstanceBuilderFactory(EntityInstanceManagerPtr entity_instance_manager, EntityTypeManagerPtr entity_type_manager);

    /// @brief Destructor.
    ~EntityInstanceBuilderFactory();

    /// @brief Initialization of the manager.
    void init();

    /// @brief Returns a new instance of a builder.
    /// @return A std::shared pointer to the entity instance builder.
    EntityInstanceBuilderPtr get_builder();

    private:
    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The entity type manager.
    EntityTypeManagerPtr entity_type_manager;

    /// The mutex of this class.
    std::mutex entity_instance_builder_factory;
};

} // namespace inexor::entity_system
