#include "MouseInputManager.hpp"
#include "spdlog/spdlog.h"

#include <GLFW/glfw3.h>

namespace inexor {
namespace input {

	MouseInputManager::MouseInputManager(
		LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
	}

	MouseInputManager::~MouseInputManager()
	{
	}

	void MouseInputManager::init()
	{
	}

	void MouseInputManager::set_mouse_callback(GLFWwindow* window)
	{
		glfwSetCursorPosCallback(window, cursor_position_callback);
		glfwSetMouseButtonCallback(window, mouse_button_callback);
		glfwSetScrollCallback(window, scroll_callback);
	}

	void MouseInputManager::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		spdlog::info("Mouse movement: {}, {}", xpos, ypos);
	}

	void MouseInputManager::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		spdlog::info("Mouse button: {}", button);
	}

	void MouseInputManager::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		spdlog::info("Mouse scroll: {}, {}", xoffset, yoffset);
	}

}
}
