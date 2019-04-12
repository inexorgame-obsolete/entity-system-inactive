#include "RendererModule.hpp"

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
			spdlog::info("GLFW ERROR {}: {}", error_code, error_message);
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
		window_manager->shutdown();
		monitor_manager->shutdown();

		// Ensure we have unset all callbacks and then terminate
		glfwSetErrorCallback(nullptr);

		glfwTerminate();
	}

	void RendererModule::update()
	{
		// Poll for and process events
		// TODO: this doesn't work well
		glfwPollEvents();
	}

	WindowManagerPtr RendererModule::get_window_manager()
	{
		return window_manager;
	}

}
}
