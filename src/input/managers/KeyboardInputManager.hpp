#pragma once

#include "input/listeners/KeyChangedListener.hpp"
#include "input/listeners/KeyPressedListener.hpp"
#include "input/listeners/KeyPressedOrRepeatedListener.hpp"
#include "input/listeners/KeyReleasedListener.hpp"
#include "input/listeners/WindowKeyChangedListener.hpp"
#include "input/listeners/WindowKeyPressedListener.hpp"
#include "input/listeners/WindowKeyPressedOrRepeatedListener.hpp"
#include "input/listeners/WindowKeyReleasedListener.hpp"

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/factories/inout/keyboard/GlobalKeyFactory.hpp"
#include "logging/managers/LogManager.hpp"

#include <boost/signals2.hpp>

namespace inexor {
namespace input {

	using LogManagerPtr = std::shared_ptr<logging::LogManager>;
	using GlobalKeyFactoryPtr = std::shared_ptr<entity_system::type_system::GlobalKeyFactory>;

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	using SignalKeyChanged = boost::signals2::signal<void(EntityInstancePtr window, int key, int scancode, int action, int mods)>;
	using SignalKeyChangedPtr = std::shared_ptr<SignalKeyChanged>;
	using SignalKeyPressed = boost::signals2::signal<void(EntityInstancePtr window, int key, int scancode, int mods)>;
	using SignalKeyPressedPtr = std::shared_ptr<SignalKeyPressed>;
	using SignalKeyPressedOrRepeated = boost::signals2::signal<void(EntityInstancePtr window, int key, int scancode, int mods)>;
	using SignalKeyPressedOrRepeatedPtr = std::shared_ptr<SignalKeyPressedOrRepeated>;
	using SignalKeyReleased = boost::signals2::signal<void(EntityInstancePtr window, int key, int scancode, int mods)>;
	using SignalKeyReleasedPtr = std::shared_ptr<SignalKeyReleased>;

	/// @class KeyboardInputManager
	/// @brief Management of the keyboard input data.
	class KeyboardInputManager
		: public std::enable_shared_from_this<KeyboardInputManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param global_key_factory The factory for creating instances of type 'GLOBAL_KEY'.
			/// @param log_manager The log manager.
			KeyboardInputManager(
				GlobalKeyFactoryPtr global_key_factory,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~KeyboardInputManager();

			/// Initialize the keyboard input module.
			void init();

			/// Shut down the keyboard input manager.
			void shutdown();

			/// @brief Creates a new entity instance of type 'GLOBAL_KEY'.
			/// @param key The key code.
			EntityInstancePtrOpt create_key(const int& key);

			/// @brief Called if the state of a key has been changed.
			/// @param window The entity instance of type 'WINDOW'.
			/// @param key
			/// @param scancode
			/// @param action
			/// @param mods
			void key_changed(EntityInstancePtr window, int key, int scancode, int action, int mods);

			/// @brief Registers a listener for the state of a key has been changed on any window.
			void register_on_key_changed(std::shared_ptr<KeyChangedListener> key_changed_listener);

			/// @brief Registers a listener for a key has been pressed on any window.
			void register_on_key_pressed(std::shared_ptr<KeyPressedListener> key_pressed_listener);

			/// @brief Registers a listener for a key has been pressed or repeated on any window.
			void register_on_key_pressed_or_repeated(std::shared_ptr<KeyPressedOrRepeatedListener> key_pressed_or_repeated_listener);

			/// @brief Registers a listener for a key has been released on any window.
			void register_on_key_released(std::shared_ptr<KeyReleasedListener> key_released_listener);

			/// @brief Registers a listener for the state of a key has been changed on a specific window.
			void register_on_window_key_changed(EntityInstancePtr window, std::shared_ptr<WindowKeyChangedListener> window_key_changed_listener);

			/// @brief Registers a listener for a key has been pressed on a specific window.
			void register_on_window_key_pressed(EntityInstancePtr window, std::shared_ptr<WindowKeyPressedListener> window_key_pressed_listener);

			/// @brief Registers a listener for a key has been pressed or repeated on a specific window.
			void register_on_window_key_pressed_or_repeated(EntityInstancePtr window, std::shared_ptr<WindowKeyPressedOrRepeatedListener> window_key_pressed_or_repeated_listener);

			/// @brief Registers a listener for a key has been released on a specific window.
			void register_on_window_key_released(EntityInstancePtr window, std::shared_ptr<WindowKeyReleasedListener> window_key_released_listener);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.input.keyboard";

		private:

			std::string get_window_name(EntityInstancePtr window);

			/// The factory for creating entity instance of type 'GLOBAL_KEY'.
			GlobalKeyFactoryPtr global_key_factory;

			/// The log manager.
			LogManagerPtr log_manager;

			/// Signal, that the state of a key has been changed on any window.
			SignalKeyChanged signal_key_changed;

			/// Signal, that the state of a key has been pressed on any window.
			SignalKeyPressed signal_key_pressed;

			/// Signal, that the state of a key has been pressed or repeated on any window.
			SignalKeyPressedOrRepeated signal_key_pressed_or_repeated;

			/// Signal, that the state of a key has been released on any window.
			SignalKeyReleased signal_key_released;

			/// Signal, that the state of a key has been changed on a specific window.
			std::unordered_map<EntityInstancePtr, SignalKeyChangedPtr> signal_window_key_changed;

			/// Signal, that the state of a key has been pressed on a specific window.
			std::unordered_map<EntityInstancePtr, SignalKeyPressedPtr> signal_window_key_pressed;

			/// Signal, that the state of a key has been pressed or repeated on a specific window.
			std::unordered_map<EntityInstancePtr, SignalKeyPressedOrRepeatedPtr> signal_window_key_pressed_or_repeated;

			/// Signal, that the state of a key has been released on a specific window.
			std::unordered_map<EntityInstancePtr, SignalKeyReleasedPtr> signal_window_key_released;

	};

}
}
