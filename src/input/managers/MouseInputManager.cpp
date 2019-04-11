#include "MouseInputManager.hpp"

#include "entity-system/model/data/DataTypes.hpp"
#include "renderer/providers/WindowEntityTypeProvider.hpp"

#include "spdlog/spdlog.h"

#include <GLFW/glfw3.h>

#include <tuple>

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
		log_manager->register_logger(LOGGER_NAME);
	}

	void MouseInputManager::shutdown()
	{
	}

	void MouseInputManager::mouse_position_changed(EntityInstancePtr window, double xpos, double ypos)
	{
		spdlog::get(LOGGER_NAME)->info("Window {} Mouse movement: {}, {}", get_window_name(window), xpos, ypos);
	}

	void MouseInputManager::mouse_button_changed(EntityInstancePtr window, int button, int action, int mods)
	{
		spdlog::get(LOGGER_NAME)->info("Window {} Mouse button: {}", get_window_name(window), button);
	}

	void MouseInputManager::mouse_scroll_changed(EntityInstancePtr window, double xoffset, double yoffset)
	{
		spdlog::get(LOGGER_NAME)->info("Window {} Mouse scroll: {}, {}", get_window_name(window), xoffset, yoffset);
	}

	std::string MouseInputManager::get_window_name(EntityInstancePtr window)
	{
		return std::get<entity_system::DataType::STRING>(window->get_attribute_instance(renderer::WindowEntityTypeProvider::WINDOW_TITLE).value()->own_value.Value());
	}

}
}
