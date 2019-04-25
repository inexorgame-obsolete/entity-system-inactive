#include "KeyboardInputManager.hpp"

#include "entity-system/model/data/DataTypes.hpp"
#include "renderer/providers/WindowEntityTypeProvider.hpp"

#include "spdlog/spdlog.h"

#include <GLFW/glfw3.h>

namespace inexor {
namespace input {

	KeyboardInputManager::KeyboardInputManager(
		GlobalKeyFactoryPtr global_key_factory,
		LogManagerPtr log_manager
	) {
		this->global_key_factory = global_key_factory;
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
		signal_key_changed.disconnect_all_slots();
		signal_key_pressed.disconnect_all_slots();
		signal_key_pressed_or_repeated.disconnect_all_slots();
		for (auto kv : signal_window_char_input)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_char_input.clear();
		for (auto kv : signal_window_key_changed)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_key_changed.clear();
		for (auto kv : signal_window_key_pressed)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_key_pressed.clear();
		for (auto kv : signal_window_key_pressed_or_repeated)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_key_pressed_or_repeated.clear();
		for (auto kv : signal_window_key_released)
		{
			kv.second->disconnect_all_slots();
		}
		signal_window_key_released.clear();
	}

	EntityInstancePtrOpt KeyboardInputManager::create_key(const int& key)
	{
		spdlog::get(LOGGER_NAME)->debug("Create entity instance for GLOBAL_KEY {}", key);
		return global_key_factory->create_instance(key);
	}

	void KeyboardInputManager::char_input(EntityInstancePtr window, unsigned int codepoint)
	{
		spdlog::get(LOGGER_NAME)->debug("codepoint: {} char: {}", codepoint, codepoint2string(codepoint));
		if (signal_window_char_input.end() != signal_window_char_input.find(window))
		{
			signal_window_char_input[window]->operator ()(window, codepoint2string(codepoint), codepoint);
		}
	}

	void KeyboardInputManager::key_changed(EntityInstancePtr window, int key, int scancode, int action, int mods)
	{
		const char* get_key_name_attempt = glfwGetKeyName(key, 0);
		std::string key_name = "?";
		if(get_key_name_attempt) key_name = get_key_name_attempt;
		spdlog::get(LOGGER_NAME)->debug("Window {} Key {} (ID {}) has been {}.", get_window_name(window), key_name, key, action ? std::string("pressed") : std::string("released"));
		signal_key_changed(window, key, scancode, action, mods);
		switch (action)
		{
			case GLFW_PRESS:
				signal_key_pressed(window, key, scancode, mods);
				signal_key_pressed_or_repeated(window, key, scancode, mods);
				break;
			case GLFW_RELEASE:
				signal_key_released(window, key, scancode, mods);
				break;
			case GLFW_REPEAT:
				signal_key_pressed_or_repeated(window, key, scancode, mods);
				break;
			default:
				break;
		}
		if (signal_window_key_changed.end() != signal_window_key_changed.find(window))
		{
			signal_window_key_changed[window]->operator ()(window, key, scancode, action, mods);
		}
		if (GLFW_PRESS == action && signal_window_key_pressed.find(window) != signal_window_key_pressed.end())
		{
			signal_window_key_pressed[window]->operator ()(window, key, scancode, mods);
		}
		if (GLFW_RELEASE == action && signal_window_key_released.find(window) != signal_window_key_released.end())
		{
			signal_window_key_released[window]->operator ()(window, key, scancode, mods);
		}
		if ((GLFW_REPEAT == action || GLFW_PRESS == action) && signal_window_key_pressed_or_repeated.find(window) != signal_window_key_pressed_or_repeated.end())
		{
			signal_window_key_pressed_or_repeated[window]->operator ()(window, key, scancode, mods);
		}

	}

	void KeyboardInputManager::register_on_key_changed(std::shared_ptr<KeyChangedListener> key_changed_listener)
	{
		signal_key_changed.connect(std::bind(&KeyChangedListener::on_key_changed, key_changed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
	}

	void KeyboardInputManager::register_on_key_pressed(std::shared_ptr<KeyPressedListener> key_pressed_listener)
	{
		signal_key_pressed.connect(std::bind(&KeyPressedListener::on_key_pressed, key_pressed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	}

	void KeyboardInputManager::register_on_key_pressed_or_repeated(std::shared_ptr<KeyPressedOrRepeatedListener> key_pressed_or_repeated_listener)
	{
		signal_key_pressed_or_repeated.connect(std::bind(&KeyPressedOrRepeatedListener::on_key_pressed_or_repeated, key_pressed_or_repeated_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	}

	void KeyboardInputManager::register_on_key_released(std::shared_ptr<KeyReleasedListener> key_released_listener)
	{
		signal_key_released.connect(std::bind(&KeyReleasedListener::on_key_released, key_released_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	}

	void KeyboardInputManager::register_on_window_char_input(EntityInstancePtr window, std::shared_ptr<WindowCharInputListener> window_char_input_listener)
	{
		if (signal_window_char_input.end() == signal_window_char_input.find(window))
		{
			auto signal = std::make_shared<SignalCharInput>();
			signal_window_char_input.insert(std::make_pair(window, signal));
		}
		signal_window_char_input[window]->connect(std::bind(&WindowCharInputListener::on_window_char_input, window_char_input_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	}

	void KeyboardInputManager::register_on_window_key_changed(EntityInstancePtr window, std::shared_ptr<WindowKeyChangedListener> window_key_changed_listener)
	{
		if (signal_window_key_changed.end() == signal_window_key_changed.find(window))
		{
			auto signal = std::make_shared<SignalKeyChanged>();
			signal_window_key_changed.insert(std::make_pair(window, signal));
		}
		signal_window_key_changed[window]->connect(std::bind(&WindowKeyChangedListener::on_window_key_changed, window_key_changed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
	}

	void KeyboardInputManager::register_on_window_key_pressed(EntityInstancePtr window, std::shared_ptr<WindowKeyPressedListener> window_key_pressed_listener)
	{
		if (signal_window_key_pressed.end() == signal_window_key_pressed.find(window))
		{
			auto signal = std::make_shared<SignalKeyPressed>();
			signal_window_key_pressed.insert(std::make_pair(window, signal));
		}
		signal_window_key_pressed[window]->connect(std::bind(&WindowKeyPressedListener::on_window_key_pressed, window_key_pressed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	}

	void KeyboardInputManager::register_on_window_key_pressed_or_repeated(EntityInstancePtr window, std::shared_ptr<WindowKeyPressedOrRepeatedListener> window_key_pressed_or_repeated_listener)
	{
		if (signal_window_key_pressed_or_repeated.end() == signal_window_key_pressed_or_repeated.find(window))
		{
			auto signal = std::make_shared<SignalKeyPressedOrRepeated>();
			signal_window_key_pressed_or_repeated.insert(std::make_pair(window, signal));
		}
		signal_window_key_pressed_or_repeated[window]->connect(std::bind(&WindowKeyPressedOrRepeatedListener::on_window_key_pressed_or_repeated, window_key_pressed_or_repeated_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	}

	void KeyboardInputManager::register_on_window_key_released(EntityInstancePtr window, std::shared_ptr<WindowKeyReleasedListener> window_key_released_listener)
	{
		if (signal_window_key_released.end() == signal_window_key_released.find(window))
		{
			auto signal = std::make_shared<SignalKeyReleased>();
			signal_window_key_released.insert(std::make_pair(window, signal));
		}
		signal_window_key_released[window]->connect(std::bind(&WindowKeyReleasedListener::on_window_key_released, window_key_released_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	}

	// TODO: if the window has been destroyed, remove the signals for this window

	std::string KeyboardInputManager::codepoint2string(unsigned int codepoint)
	{
		char c[5] = { 0x00, 0x00, 0x00, 0x00, 0x00 };
		if (codepoint <= 0x7F)
		{
			c[0] = codepoint;
		} else if (codepoint <= 0x7FF)
		{
			c[0] = (codepoint >> 6) + 192;
			c[1] = (codepoint & 63) + 128;
		} else if (0xd800 <= codepoint && codepoint <= 0xdfff)
		{
	    	//invalid block of utf8
	    } else if (codepoint <= 0xFFFF)
	    {
	    	c[0] = (codepoint >> 12) + 224;
	    	c[1] = ((codepoint >> 6) & 63) + 128;
	    	c[2] = (codepoint & 63) + 128;
	    } else if (codepoint <= 0x10FFFF)
	    {
	    	c[0] = (codepoint >> 18) + 240;
	    	c[1] = ((codepoint >> 12) & 63) + 128;
	    	c[2] = ((codepoint >> 6) & 63) + 128;
	    	c[3] = (codepoint & 63) + 128;
	    }
	    return std::string(c);
	}

	std::string KeyboardInputManager::get_window_name(EntityInstancePtr window)
	{
		return window->get<entity_system::DataType::STRING>(renderer::WindowEntityTypeProvider::WINDOW_TITLE);
	}

}
}
