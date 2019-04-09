#include "RendererModule.hpp"

#include <GLFW/glfw3.h>

namespace inexor {
namespace renderer {

	RendererModule::RendererModule(
		WindowManagerPtr window_manager,
		TriangleExamplePtr triangle_example
	)
	{
		this->window_manager = window_manager;
		this->triangle_example = triangle_example;
	}

	RendererModule::~RendererModule()
	{
	}

	void RendererModule::init()
	{
		// Initialize the GLFW library.

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if(!glfwInit())
		{
			spdlog::error("Failed to initialize glfw!");
			std::exit(1);
		}

		window_manager->init();
		triangle_example->init();
	}

	void RendererModule::shutdown()
	{
		triangle_example->shutdown();
		window_manager->shutdown();

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
