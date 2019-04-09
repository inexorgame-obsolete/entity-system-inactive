#include "WindowManager.hpp"

//#include <Magnum/GL/Buffer.h>
//#include <Magnum/GL/DefaultFramebuffer.h>
//#include <Magnum/GL/Renderer.h>
#include <Magnum/Platform/GLContext.h>
#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

namespace inexor {
namespace renderer {

	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityAttributeInstanceOpt = std::optional<EntityAttributeInstancePtr>;

	WindowManager::WindowManager(
		WindowFactoryPtr window_factory,
		KeyboardInputManagerPtr keyboard_input_manager,
		MouseInputManagerPtr mouse_input_manager,
		EntityInstanceManagerPtr entity_instance_manager,
		ConnectorManagerPtr connector_manager,
		LogManagerPtr log_manager
	) {
		this->window_factory = window_factory;
		this->keyboard_input_manager = keyboard_input_manager;
		this->mouse_input_manager = mouse_input_manager;
		this->entity_instance_manager = entity_instance_manager;
		this->connector_manager = connector_manager;
		this->log_manager = log_manager;
		this->window_count = 0;
	}

	WindowManager::~WindowManager()
	{
	}

	void WindowManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		create_window("Test 1", 0, 0, 300, 300);
		create_window("Test 2", 300, 0, 300, 300);
		create_window("Test 3", 0, 300, 300, 300);
		create_window("Test 4", 300, 300, 300, 300);
	}

	void WindowManager::shutdown()
	{
		log_manager->register_logger(LOGGER_NAME);
		for (auto& kv : windows) {
			destroy_window(kv.first);
		}
	}

	/// @brief Creates a new window with the given title, position and dimensions.
	/// @param window The GLFWwindow instance.
	EntityInstancePtr WindowManager::create_window(std::string title, int x, int y, int width, int height)
	{

		spdlog::get(WindowManager::LOGGER_NAME)->info("Creating window!");

		// Create a windowed mode window and its OpenGL context.
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		GLFWwindow* const glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		if (glfw_window)
		{
			glfwSetWindowPos(glfw_window, x, y);

			EntityInstancePtrOpt o_window = window_factory->create_instance(title, x, y, width, height);
			if (o_window.has_value())
			{
				EntityInstancePtr window = o_window.value();

				std::thread window_thread(&renderer::WindowManager::start_window_thread, this, window);
				window_thread.detach();

				// Track the glfw window and the entity instance.
				windows[window] = std::make_pair(glfw_window, std::move(window_thread));
				window_entities[glfw_window] = window;

				// Set the window's user pointer to the window manager
				glfwSetWindowUserPointer(glfw_window, this);

				// Register the close callback
				glfwSetWindowCloseCallback(glfw_window, [] (GLFWwindow* _glfw_window) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_closed(_glfw_window);
				});

				// Register the focus callback
				glfwSetWindowFocusCallback(glfw_window, [] (GLFWwindow* _glfw_window, int has_focus) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_focused(_glfw_window, has_focus == GLFW_TRUE);
				});

				// Register the iconify callback
				glfwSetWindowIconifyCallback(glfw_window, [] (GLFWwindow* _glfw_window, int is_iconified) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_iconified(_glfw_window, is_iconified == GLFW_TRUE);
				});

				// Register the maximize callback
				glfwSetWindowMaximizeCallback(glfw_window, [] (GLFWwindow* _glfw_window, int is_maximized) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_maximized(_glfw_window, is_maximized == GLFW_TRUE);
				});

				// Register the window size callback
				glfwSetWindowPosCallback(glfw_window, [] (GLFWwindow* _glfw_window, int x, int y) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_position_changed(_glfw_window, x, y);
				});

				// Register the window size callback
				glfwSetWindowSizeCallback(glfw_window, [] (GLFWwindow* _glfw_window, int width, int height) {
					((WindowManager*) glfwGetWindowUserPointer(_glfw_window))->window_size_changed(_glfw_window, width, height);
				});

				// Register keyboard input handler.
				keyboard_input_manager->set_keyboard_callback(glfw_window);

				// Register mouse input handler.
				// This takes care of both mouse buttons and mouse movement.
				mouse_input_manager->set_mouse_callback(glfw_window);

				// TEST!
				glfwSetWindowOpacity(glfw_window, 0.5f);

				glfwShowWindow(glfw_window);

				window_count++;
				spdlog::get(WindowManager::LOGGER_NAME)->info("Window count: {}", window_count);

				// TODO: return an std::optional!
				return window;

			} else {
				spdlog::get(WindowManager::LOGGER_NAME)->error("Failed to create entity instance!");
				// TODO: return an std::optional!
				return nullptr;
			}
		} else {
			spdlog::get(WindowManager::LOGGER_NAME)->error("Failed to create window!");
			// TODO: return an std::optional!
			return nullptr;
		}
	}

	/// @brief Destroys the given window.
	/// @param window The entity instance of type WINDOW.
	void WindowManager::destroy_window(EntityInstancePtr window)
	{
		std::thread window_thread = std::move(windows[window].second);
		GLFWwindow *glfw_window = windows[window].first;

		spdlog::get(WindowManager::LOGGER_NAME)->info("Attempting to close window!");

		// Signal window to be closed
		glfwSetWindowShouldClose(glfw_window, GLFW_TRUE);

		// Wait for window thread state being released
		while(window_thread_state[window])
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}

		spdlog::get(WindowManager::LOGGER_NAME)->info("Window thread state false!");

		// Wait for the window thread being joined
		window_thread.join();

		spdlog::get(WindowManager::LOGGER_NAME)->info("Window thread joined!");
	}


	void WindowManager::close_window(EntityInstancePtr window)
	{
		glfwSetWindowShouldClose(windows[window].first, GLFW_TRUE);
	}

	void WindowManager::set_window_size(EntityInstancePtr window, int width, int height)
	{
		set_window_size(windows[window].first, width, height);
	}

	void WindowManager::set_window_size(GLFWwindow* glfw_window, int width, int height)
	{
		glfwSetWindowSize(glfw_window, width, height);
	}

	void WindowManager::window_closed(GLFWwindow* glfw_window)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window closed!");
	}

	void WindowManager::window_focused(GLFWwindow* glfw_window, bool has_focus)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->error("EVT: Window focus changed: {}", has_focus);
		EntityInstancePtr window = window_entities[glfw_window];
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_FOCUSED).value()->own_value.Set(has_focus);
	}

	void WindowManager::window_iconified(GLFWwindow* glfw_window, bool is_iconified)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window iconification state changed: {}", is_iconified);
		EntityInstancePtr window = window_entities[glfw_window];
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_ICONIFIED).value()->own_value.Set(is_iconified);
	}

	void WindowManager::window_maximized(GLFWwindow* glfw_window, bool is_maximized)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window maximize state changed: {}", is_maximized);
		EntityInstancePtr window = window_entities[glfw_window];
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_MAXIMIZED).value()->own_value.Set(is_maximized);
	}

	void WindowManager::window_position_changed(GLFWwindow* glfw_window, int x, int y)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window position changed: {}:{}", x, y);
		EntityInstancePtr window = window_entities[glfw_window];
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_X).value()->own_value.Set(x);
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_POSITION_Y).value()->own_value.Set(y);
	}

	void WindowManager::window_size_changed(GLFWwindow* glfw_window, int width, int height)
	{
		spdlog::get(WindowManager::LOGGER_NAME)->info("EVT: Window size changed: {}:{}", width, height);
		EntityInstancePtr window = window_entities[glfw_window];
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_WIDTH).value()->own_value.Set(width);
		window->get_attribute_instance(WindowEntityTypeProvider::WINDOW_HEIGHT).value()->own_value.Set(height);
	}

	void WindowManager::start_window_thread(EntityInstancePtr window)
	{
		window_thread_state[window] = true;

		GLFWwindow *glfw_window = windows[window].first;

		// Make the window's context current.
		glfwMakeContextCurrent(glfw_window);

		// Create Magnum context in an isolated scope.
		Magnum::Platform::GLContext ctx{};

		// Loop until the user closes the window.
		while(!glfwWindowShouldClose(glfw_window))
		{

			// TODO: render worlds

			// TODO: render user interfaces

			// Render custom on front
			for (std::function renderer_function : window_render_functions[window])
			{
				renderer_function(window, glfw_window);
			}

			// Swap front and back buffers.
			glfwSwapBuffers(glfw_window);

			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}

		// Detach the window's current context.
		glfwMakeContextCurrent(nullptr);

		window_thread_state[window] = false;

		spdlog::get(WindowManager::LOGGER_NAME)->info("Window has been closed!");

		// Untrack the glfw window
		window_entities.erase(glfw_window);

		// Destroy the glfw window object
		glfwDestroyWindow(glfw_window);

		// Remove render functions
		window_render_functions.erase(window);

		// Untrack the entity instance
		windows.erase(window);

		// Delete entity instance
		entity_instance_manager->delete_entity_instance(window);

		window_count--;
		spdlog::get(WindowManager::LOGGER_NAME)->info("Window count: {}", window_count);

	}

	void WindowManager::make_current(EntityInstancePtr window)
	{
		glfwMakeContextCurrent(windows[window].first);

		// Create Magnum context in an isolated scope.
		Magnum::Platform::GLContext ctx{};
	}

	void WindowManager::register_render_function(EntityInstancePtr window, std::function<void(EntityInstancePtr, GLFWwindow*)> render_function)
	{
		window_render_functions[window].push_back(render_function);
	}

	int WindowManager::get_window_count()
	{
		return window_count;
	}

}
}
