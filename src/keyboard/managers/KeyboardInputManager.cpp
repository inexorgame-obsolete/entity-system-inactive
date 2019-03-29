#include "KeyboardInputManager.hpp"
#include "spdlog/spdlog.h"

#include <GLFW/glfw3.h>

namespace inexor {
namespace input {
namespace keyboard {

	KeyboardInputManager::KeyboardInputManager(
		LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
	}

	KeyboardInputManager::~KeyboardInputManager()
	{
	}

    void KeyboardInputManager::init()
    {
    }

    void KeyboardInputManager::keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        std::string key_name = glfwGetKeyName(key, 0);
        spdlog::info("Key {} (ID {}) has been {}.", key_name, key, glfwGetKey(window, key) ? std::string("pressed") : std::string("released"));
    }

}
}
}
