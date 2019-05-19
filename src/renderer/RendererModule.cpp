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
		FontManagerPtr font_manager,
		LoadingScreenPtr loading_screen
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		, TriangleExamplePtr triangle_example
#endif
	)
	{
		this->monitor_manager = monitor_manager;
		this->window_manager = window_manager;
		this->font_manager = font_manager;
		this->loading_screen = loading_screen;
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		this->triangle_example = triangle_example;
#endif
	}

	RendererModule::~RendererModule()
	{
	}

	void RendererModule::init()
	{
		// TODO: Move initialization of GLFW upwards (ClientModule)
		// Initialize the GLFW library.

		// Set error callback
		glfwSetErrorCallback([] (int error_code, const char* error_message) {
			if (error_code == 65545) return;
			spdlog::error("GLFW ERROR {}: {}", error_code, error_message);
		});

		if(!glfwInit())
		{
			spdlog::error("Failed to initialize glfw!");
			std::exit(1);
		}

		monitor_manager->init();
		window_manager->init();
		font_manager->init();
		loading_screen->init();
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		triangle_example->init();
#endif
	}

	void RendererModule::shutdown()
	{
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		triangle_example->shutdown();
#endif
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

}
}
