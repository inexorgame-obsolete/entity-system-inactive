#include "RendererModule.hpp"

// Statically import the magnum plugins
// This is the only place to do this!
#include "renderer/plugins/MagnumPlugins.cpp"

#include <GLFW/glfw3.h>

namespace inexor {
namespace renderer {

	RendererModule::RendererModule(
		MonitorManagerPtr monitor_manager,
		WindowManagerPtr window_manager,
		LoadingScreenPtr loading_screen,
		TriangleExamplePtr triangle_example
	)
	{
		this->monitor_manager = monitor_manager;
		this->window_manager = window_manager;
		this->loading_screen = loading_screen;
		this->triangle_example = triangle_example;
	}

	RendererModule::~RendererModule()
	{
	}

	void RendererModule::init()
	{
		// Initialize the GLFW library.

		// Set error callback
		glfwSetErrorCallback([] (int error_code, const char* error_message) {
			spdlog::error("GLFW ERROR {}: {}", error_code, error_message);
		});

		if(!glfwInit())
		{
			spdlog::error("Failed to initialize glfw!");
			std::exit(1);
		}

		monitor_manager->init();
		window_manager->init();
		loading_screen->init();
		triangle_example->init();
	}

	void RendererModule::shutdown()
	{
		triangle_example->shutdown();
		loading_screen->shutdown();
		window_manager->shutdown();
		monitor_manager->shutdown();

		// Ensure we have unset all callbacks and then terminate
		glfwSetErrorCallback(nullptr);

		glfwTerminate();
	}

	void RendererModule::update()
	{
		// Poll for and process events
		glfwPollEvents();
	}

//	WindowManagerPtr RendererModule::get_window_manager()
//	{
//		return window_manager;
//	}

}
}
