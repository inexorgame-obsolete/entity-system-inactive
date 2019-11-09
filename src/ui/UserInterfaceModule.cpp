#include "UserInterfaceModule.hpp"

#include <GLFW/glfw3.h>

#include <utility>

namespace inexor::ui {

UserInterfaceModule::UserInterfaceModule(MonitorManagerPtr monitor_manager, WindowManagerPtr window_manager)
{
    this->monitor_manager = std::move(monitor_manager);
    this->window_manager = std::move(window_manager);
}

UserInterfaceModule::~UserInterfaceModule() = default;

void UserInterfaceModule::init()
{
    // TODO: Move initialization of GLFW upwards (ClientModule)
    // Initialize the GLFW library.

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

    monitor_manager->init();
    window_manager->init();
}

void UserInterfaceModule::shutdown()
{
    window_manager->shutdown();
    monitor_manager->shutdown();

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

} // namespace inexor::renderer
