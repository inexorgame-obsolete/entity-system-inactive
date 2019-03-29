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

    void KeyboardInputManager::set_keyboard_callback(GLFWwindow* window)
    {
        glfwSetKeyCallback(window, keyboard_input_callback);
    }

    /// @warning We can't use LOGGER_NAME inside of a static class method because it causes runtime errors!
    void KeyboardInputManager::keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        const char* get_key_name_attempt = glfwGetKeyName(key, 0);
        std::string key_name = "?";
        if(get_key_name_attempt) key_name = get_key_name_attempt;
        spdlog::info("Key {} (ID {}) has been {}.", key_name, key, glfwGetKey(window, key) ? std::string("pressed") : std::string("released"));
    }

}
}
}
