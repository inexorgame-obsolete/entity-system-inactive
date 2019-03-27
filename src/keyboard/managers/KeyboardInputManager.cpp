#include "KeyboardInputManager.hpp"

#include "spdlog/spdlog.h"

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

}
}
}
