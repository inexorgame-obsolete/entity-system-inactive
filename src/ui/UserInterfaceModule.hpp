#pragma once

#include "ui/managers/MonitorManager.hpp"
#include "ui/managers/WindowManager.hpp"

namespace inexor::ui {

/// @class UserInterfaceModule
/// @brief This module is responsible for the management of the windows,
/// the rendering of the world (octree) and the rendering of the user
/// interface.
class UserInterfaceModule
{
    using MonitorManagerPtr = std::shared_ptr<MonitorManager>;
    using WindowManagerPtr = std::shared_ptr<WindowManager>;

    public:
    /// @brief Constructor.
    /// @param monitor_manager The monitor manager.
    /// @param window_manager The window manager.
    UserInterfaceModule(MonitorManagerPtr monitor_manager, WindowManagerPtr window_manager);

    /// Destructor.
    ~UserInterfaceModule();

    /// Initialization of the renderer module.
    void init();

    /// Shutdown of the renderer module.
    void shutdown();

    /// Updates the frame in main thread.
    void update();

    private:
    /// The monitor manager.
    MonitorManagerPtr monitor_manager;

    /// The window manager.
    WindowManagerPtr window_manager;
};

} // namespace inexor::ui
