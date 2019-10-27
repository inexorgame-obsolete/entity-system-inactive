#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "renderer/providers/MonitorEntityTypeProvider.hpp"

namespace inexor::renderer {

using MonitorEntityTypeProviderPtr = std::shared_ptr<MonitorEntityTypeProvider>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

/// @class MonitorFactory
/// @brief Factory for creating monitors.
class MonitorFactory
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param monitor_entity_type_provider The entity type provider.
    /// @param entity_instance_builder_factory The entity instance builder factory.
    /// @param entity_instance_manager The entity instance manager.
    MonitorFactory(MonitorEntityTypeProviderPtr monitor_entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, EntityInstanceManagerPtr entity_instance_manager);

    /// Destructor.
    ~MonitorFactory();

    /// Creates a new monitor with the given title, coordinates and dimensions.
    /// @param title The title of the monitor.
    /// @param x The x position of the monitor.
    /// @param y The y position of the monitor.
    /// @param width The width of the monitor.
    /// @param height The height of the monitor.
    /// @param is_primary If true, the monitor is the primary monitor.
    EntityInstancePtrOpt create_instance(const std::string &title, int x, int y, int width, int height, bool is_primary);

    private:
    /// The entity type provider.
    MonitorEntityTypeProviderPtr monitor_entity_type_provider;

    /// The entity instance builder factory.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;
};

} // namespace inexor::renderer
