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
        if(GLFW_PRESS == action)
        {
            spdlog::info("A key has been pressed!");
        }
        else if(GLFW_RELEASE == action)
        {
            spdlog::info("A key has been released!");
        }
    }

}
}
}
