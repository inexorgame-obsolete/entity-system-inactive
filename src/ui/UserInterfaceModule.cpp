#include "UserInterfaceModule.hpp"

#include <GLFW/glfw3.h>

#include <utility>

namespace inexor::ui {

UserInterfaceModule::UserInterfaceModule(UserInterfaceFactoriesPtr user_interface_factories, MonitorManagerPtr monitor_manager, WindowManagerPtr window_manager)
    : LifeCycleComponent(user_interface_factories, monitor_manager, window_manager)
{
    this->user_interface_factories = std::move(user_interface_factories);
    this->monitor_manager = std::move(monitor_manager);
    this->window_manager = std::move(window_manager);
}

UserInterfaceModule::~UserInterfaceModule() = default;

void UserInterfaceModule::init()
{
    // Initializes the GLFW library.

    // Set error callback
    glfwSetErrorCallback([](int error_code, const char *error_message) {
        if (error_code == 65545)
            return;
        spdlog::error("GLFW ERROR {}: {}", error_code, error_message);
    });

    if (!glfwInit())
    {
        spdlog::error("Failed to initialize glfw!");
        std::exit(1);
    }
}

void UserInterfaceModule::destroy()
{
    // Ensure we have unset all callbacks and then terminate
    glfwSetErrorCallback(nullptr);

    glfwTerminate();
}

void UserInterfaceModule::update()
{
    // Wrap all events in a single reactive transaction
    // in order to avoid feedback cycles
    DoTransaction<entity_system::D>([] {
        // Poll for and process events
        glfwPollEvents();
    });
}

std::string UserInterfaceModule::get_component_name()
{
    return "UserInterfaceModule";
}

} // namespace inexor::renderer
