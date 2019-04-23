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
		signal_mouse_button_changed.disconnect_all_slots();
		signal_mouse_button_pressed.disconnect_all_slots();
		signal_mouse_button_released.disconnect_all_slots();
		for (auto kv : signal_window_mouse_button_changed)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_mouse_button_changed.clear();
		for (auto kv : signal_window_mouse_button_pressed)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_mouse_button_pressed.clear();
		for (auto kv : signal_window_mouse_button_released)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_mouse_button_released.clear();
		for (auto kv : signal_window_mouse_moved)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_mouse_moved.clear();
		for (auto kv : signal_window_mouse_scrolled)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_mouse_scrolled.clear();
	}

	void MouseInputManager::mouse_position_changed(EntityInstancePtr window, double xpos, double ypos)
	{
		spdlog::get(LOGGER_NAME)->debug("Window {} Mouse movement: {}, {}", get_window_name(window), xpos, ypos);
		if (signal_window_mouse_moved.end() != signal_window_mouse_moved.find(window))
		{
			signal_window_mouse_moved[window]->operator ()(window, xpos, ypos);
		}
	}

	void MouseInputManager::mouse_button_changed(EntityInstancePtr window, int button, int action, int mods)
	{
		spdlog::get(LOGGER_NAME)->info("Window {} Mouse button: {} Action: {} Mods: {}", get_window_name(window), button, action, mods);
		signal_mouse_button_changed(window, button, action, mods);
		switch (action)
		{
			case GLFW_PRESS:
				signal_mouse_button_pressed(window, button, mods);
				break;
			case GLFW_RELEASE:
				signal_mouse_button_released(window, button, mods);
				break;
			default:
				break;
		}
		if (signal_window_mouse_button_changed.end() != signal_window_mouse_button_changed.find(window))
		{
			signal_window_mouse_button_changed[window]->operator ()(window, button, action, mods);
		}
		if (GLFW_PRESS == action && signal_window_mouse_button_pressed.find(window) != signal_window_mouse_button_pressed.end())
		{
			signal_window_mouse_button_pressed[window]->operator ()(window, button, mods);
		}
		if (GLFW_RELEASE == action && signal_window_mouse_button_released.find(window) != signal_window_mouse_button_released.end())
		{
			signal_window_mouse_button_released[window]->operator ()(window, button, mods);
		}
	}

	void MouseInputManager::mouse_scroll_changed(EntityInstancePtr window, double xoffset, double yoffset)
	{
		spdlog::get(LOGGER_NAME)->info("Window {} Mouse scroll: {}, {}", get_window_name(window), xoffset, yoffset);
		if (signal_window_mouse_scrolled.end() != signal_window_mouse_scrolled.find(window))
		{
			signal_window_mouse_scrolled[window]->operator ()(window, xoffset, yoffset);
		}
	}

	void MouseInputManager::register_on_mouse_button_changed(std::shared_ptr<MouseButtonChangedListener> mouse_button_changed_listener)
	{
		signal_mouse_button_changed.connect(std::bind(&MouseButtonChangedListener::on_mouse_button_changed, mouse_button_changed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	}

	void MouseInputManager::register_on_mouse_button_pressed(std::shared_ptr<MouseButtonPressedListener> mouse_button_pressed_listener)
	{
		signal_mouse_button_pressed.connect(std::bind(&MouseButtonPressedListener::on_mouse_button_pressed, mouse_button_pressed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	}

	void MouseInputManager::register_on_mouse_button_released(std::shared_ptr<MouseButtonReleasedListener> mouse_button_released_listener)
	{
		signal_mouse_button_released.connect(std::bind(&MouseButtonReleasedListener::on_mouse_button_released, mouse_button_released_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	}

	void MouseInputManager::register_on_window_mouse_button_changed(EntityInstancePtr window, std::shared_ptr<WindowMouseButtonChangedListener> window_mouse_button_changed_listener)
	{
		if (signal_window_mouse_button_changed.end() == signal_window_mouse_button_changed.find(window))
		{
			auto signal = std::make_shared<SignalMouseButtonChanged>();
			signal_window_mouse_button_changed.insert(std::make_pair(window, signal));
		}
		signal_window_mouse_button_changed[window]->connect(std::bind(&WindowMouseButtonChangedListener::on_window_mouse_button_changed, window_mouse_button_changed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	}

	void MouseInputManager::register_on_window_mouse_button_pressed(EntityInstancePtr window, std::shared_ptr<WindowMouseButtonPressedListener> window_mouse_button_pressed_listener)
	{
		if (signal_window_mouse_button_pressed.end() == signal_window_mouse_button_pressed.find(window))
		{
			auto signal = std::make_shared<SignalMouseButtonPressed>();
			signal_window_mouse_button_pressed.insert(std::make_pair(window, signal));
		}
		signal_window_mouse_button_pressed[window]->connect(std::bind(&WindowMouseButtonPressedListener::on_window_mouse_button_pressed, window_mouse_button_pressed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	}

	void MouseInputManager::register_on_window_mouse_button_released(EntityInstancePtr window, std::shared_ptr<WindowMouseButtonReleasedListener> window_mouse_button_released_listener)
	{
		if (signal_window_mouse_button_released.end() == signal_window_mouse_button_released.find(window))
		{
			auto signal = std::make_shared<SignalMouseButtonReleased>();
			signal_window_mouse_button_released.insert(std::make_pair(window, signal));
		}
		signal_window_mouse_button_released[window]->connect(std::bind(&WindowMouseButtonReleasedListener::on_window_mouse_button_released, window_mouse_button_released_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	}

	void MouseInputManager::register_on_window_mouse_moved(EntityInstancePtr window, std::shared_ptr<WindowMouseMovedListener> window_mouse_moved_listener)
	{
		if (signal_window_mouse_moved.end() == signal_window_mouse_moved.find(window))
		{
			auto signal = std::make_shared<SignalMouseMoved>();
			signal_window_mouse_moved.insert(std::make_pair(window, signal));
		}
		signal_window_mouse_moved[window]->connect(std::bind(&WindowMouseMovedListener::on_window_mouse_moved, window_mouse_moved_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	}

	void MouseInputManager::register_on_window_mouse_scrolled(EntityInstancePtr window, std::shared_ptr<WindowMouseScrolledListener> window_mouse_scrolled_listener)
	{
		if (signal_window_mouse_scrolled.end() == signal_window_mouse_scrolled.find(window))
		{
			auto signal = std::make_shared<SignalMouseScrolled>();
			signal_window_mouse_scrolled.insert(std::make_pair(window, signal));
		}
		signal_window_mouse_scrolled[window]->connect(std::bind(&WindowMouseScrolledListener::on_window_mouse_scrolled, window_mouse_scrolled_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	}

	// TODO: if the window has been destroyed, remove the signals for this window

	std::string MouseInputManager::get_window_name(EntityInstancePtr window)
	{
		return window->get<entity_system::DataType::STRING>(renderer::WindowEntityTypeProvider::WINDOW_TITLE);
	}

}
}
