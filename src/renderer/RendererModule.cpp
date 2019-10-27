#include "RendererModule.hpp"

// Statically import the magnum plugins
// This is the only place to do this!
#include "renderer/plugins/MagnumPlugins.cpp"

#include <GLFW/glfw3.h>

#include <utility>

namespace inexor::renderer {

RendererModule::RendererModule(MonitorManagerPtr monitor_manager, WindowManagerPtr window_manager, FontManagerPtr font_manager, LoadingScreenPtr loading_screen, TriangleExamplePtr triangle_example)
{
    this->monitor_manager = std::move(monitor_manager);
    this->window_manager = std::move(window_manager);
    this->font_manager = std::move(font_manager);
    this->loading_screen = std::move(loading_screen);
    this->triangle_example = std::move(triangle_example);
}

RendererModule::~RendererModule() = default;

void RendererModule::init()
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
    font_manager->init();
    loading_screen->init();
    triangle_example->init();
}

void RendererModule::shutdown()
{
    triangle_example->shutdown();
    loading_screen->shutdown();
    font_manager->shutdown();
    window_manager->shutdown();
    monitor_manager->shutdown();

    // Ensure we have unset all callbacks and then terminate
    glfwSetErrorCallback(nullptr);

    glfwTerminate();
}

void RendererModule::update()
{
    // Wrap all events in a single reactive transaction
    // in order to avoid feedback cycles
    DoTransaction<D>([] {
        // Poll for and process events
        glfwPollEvents();
    });
}

} // namespace inexor::renderer
