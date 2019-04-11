#include "KeyboardInputManager.hpp"

#include "entity-system/model/data/DataTypes.hpp"
#include "renderer/providers/WindowEntityTypeProvider.hpp"

#include "spdlog/spdlog.h"

#include <GLFW/glfw3.h>

namespace inexor {
namespace input {

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
		log_manager->register_logger(LOGGER_NAME);
	}

	void KeyboardInputManager::shutdown()
	{
	}

	void KeyboardInputManager::key_changed(EntityInstancePtr window, int key, int scancode, int action, int mods)
	{
		const char* get_key_name_attempt = glfwGetKeyName(key, 0);
		std::string key_name = "?";
		if(get_key_name_attempt) key_name = get_key_name_attempt;
		spdlog::get(LOGGER_NAME)->info("Window {} Key {} (ID {}) has been {}.", get_window_name(window), key_name, key, action ? std::string("pressed") : std::string("released"));
	}

	std::string KeyboardInputManager::get_window_name(EntityInstancePtr window)
	{
		return std::get<entity_system::DataType::STRING>(window->get_attribute_instance(renderer::WindowEntityTypeProvider::WINDOW_TITLE).value()->own_value.Value());
	}

}
}
