#pragma once

#include "base/LifeCycleComponent.hpp"
#include "ui/factories/UserInterfaceFactories.hpp"
#include "ui/managers/MonitorManager.hpp"
#include "ui/managers/WindowManager.hpp"

namespace inexor::ui {

/// @class UserInterfaceModule
/// @brief This module is responsible for the management of the windows,
/// the rendering of the world (octree) and the rendering of the user
/// interface.
class UserInterfaceModule : public LifeCycleComponent
{
    using UserInterfaceFactoriesPtr = std::shared_ptr<UserInterfaceFactories>;
    using MonitorManagerPtr = std::shared_ptr<MonitorManager>;
    using WindowManagerPtr = std::shared_ptr<WindowManager>;

    public:
    /// @brief Constructor.
    /// @param user_interface_factories The user interface factories.
    /// @param monitor_manager The monitor manager.
    /// @param window_manager The window manager.
    UserInterfaceModule(UserInterfaceFactoriesPtr user_interface_factories, MonitorManagerPtr monitor_manager, WindowManagerPtr window_manager);

    /// Destructor.
    ~UserInterfaceModule();

    /// Initialization of the renderer module.
    void init() override;

    /// Shutdown of the renderer module.
    void destroy() override;

    /// Updates the frame in main thread.
    void update();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The user interface factories.
    UserInterfaceFactoriesPtr user_interface_factories;

    /// The monitor manager.
    MonitorManagerPtr monitor_manager;

    /// The window manager.
    WindowManagerPtr window_manager;
};

} // namespace inexor::ui
