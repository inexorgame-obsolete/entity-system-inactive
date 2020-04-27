#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"

namespace inexor::ui {

using EntityInstanceBuilderFactoryPtr = std::shared_ptr<entity_system::EntityInstanceBuilderFactory>;
using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

/// @class WindowFactory
/// @brief Factory for creating windows.
class WindowFactory : public LifeCycleComponent
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory The entity instance builder factory.
    /// @param entity_instance_manager The entity instance manager.
    WindowFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, EntityInstanceManagerPtr entity_instance_manager);

    /// Destructor.
    ~WindowFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Creates a new window with the given title, coordinates and dimensions.
    /// @param id The id of the window.
    /// @param title The title of the window.
    /// @param x The x position of the window.
    /// @param y The y position of the window.
    /// @param width The width of the window.
    /// @param height The height of the window.
    EntityInstancePtrOpt create_instance(int id, const std::string &title, int x, int y, int width, int height);

    EntityInstancePtrOpt create_instance(int id, const std::string &title, int x, int y, int width, int height, float opacity);

    EntityInstancePtrOpt create_instance(int id, const std::string &title, int x, int y, int width, int height, float opacity, bool visible, bool fullscreen, bool iconified, bool maximized, bool focused, bool vsync, float fps);

    private:
    /// The entity instance builder factory.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;
};

} // namespace inexor::ui
