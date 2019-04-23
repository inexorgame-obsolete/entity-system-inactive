#pragma once

#include "input/listeners/MouseButtonChangedListener.hpp"
#include "input/listeners/MouseButtonPressedListener.hpp"
#include "input/listeners/MouseButtonReleasedListener.hpp"
#include "input/listeners/WindowMouseButtonChangedListener.hpp"
#include "input/listeners/WindowMouseButtonPressedListener.hpp"
#include "input/listeners/WindowMouseButtonReleasedListener.hpp"
#include "input/listeners/WindowMouseMovedListener.hpp"
#include "input/listeners/WindowMouseScrolledListener.hpp"

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/factories/inout/mouse/GlobalMouseButtonFactory.hpp"
#include "logging/managers/LogManager.hpp"

#include <boost/signals2.hpp>

namespace inexor {
namespace input {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using GlobalMouseButtonFactoryPtr = std::shared_ptr<entity_system::type_system::GlobalMouseButtonFactory>;

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	using SignalMouseButtonChanged = boost::signals2::signal<void(EntityInstancePtr window, int button, int action, int mods)>;
	using SignalMouseButtonChangedPtr = std::shared_ptr<SignalMouseButtonChanged>;
	using SignalMouseButtonPressed = boost::signals2::signal<void(EntityInstancePtr window, int button, int mods)>;
	using SignalMouseButtonPressedPtr = std::shared_ptr<SignalMouseButtonPressed>;
	using SignalMouseButtonReleased = boost::signals2::signal<void(EntityInstancePtr window, int button, int mods)>;
	using SignalMouseButtonReleasedPtr = std::shared_ptr<SignalMouseButtonReleased>;
	using SignalMouseMoved = boost::signals2::signal<void(EntityInstancePtr window, double xpos, double ypos)>;
	using SignalMouseMovedPtr = std::shared_ptr<SignalMouseMoved>;
	using SignalMouseScrolled = boost::signals2::signal<void(EntityInstancePtr window, double xoffset, double yoffset)>;
	using SignalMouseScrolledPtr = std::shared_ptr<SignalMouseScrolled>;

	/// @class MouseInputManager
	/// @brief Management of the Mouse input data.
	class MouseInputManager
		: public std::enable_shared_from_this<MouseInputManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param log_manager The log manager.
			MouseInputManager(
				GlobalMouseButtonFactoryPtr global_mouse_button_factory,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~MouseInputManager();

			/// Initialize the mouse input manager.
			void init();

			/// Shut down the mouse input manager.
			void shutdown();

			/// @brief Creates a new entity instance of type 'GLOBAL_MOUSE_BUTTON'.
			/// @param button The button number.
			EntityInstancePtrOpt create_mouse_button(const int& button);

			/// @brief The mouse position has been changed.
			void mouse_position_changed(EntityInstancePtr window, double xpos, double ypos);

			/// @brief The state of the mouse button has been changed.
			void mouse_button_changed(EntityInstancePtr window, int button, int action, int mods);

			/// @brief The state of the mouse scroll has been changed.
			void mouse_scroll_changed(EntityInstancePtr window, double xoffset, double yoffset);

			/// @brief Registers a listener for mouse button change on any window.
			void register_on_mouse_button_changed(std::shared_ptr<MouseButtonChangedListener> mouse_button_changed_listener);

			/// @brief Registers a listener for mouse button press on any window.
			void register_on_mouse_button_pressed(std::shared_ptr<MouseButtonPressedListener> mouse_button_pressed_listener);

			/// @brief Registers a listener for mouse button release on any window.
			void register_on_mouse_button_released(std::shared_ptr<MouseButtonReleasedListener> mouse_button_released_listener);

			/// @brief Registers a listener for mouse button change on a specific window.
			void register_on_window_mouse_button_changed(EntityInstancePtr window, std::shared_ptr<WindowMouseButtonChangedListener> window_mouse_button_changed_listener);

			/// @brief Registers a listener for mouse button press on a specific window.
			void register_on_window_mouse_button_pressed(EntityInstancePtr window, std::shared_ptr<WindowMouseButtonPressedListener> window_mouse_button_pressed_listener);

			/// @brief Registers a listener for mouse button release on a specific window.
			void register_on_window_mouse_button_released(EntityInstancePtr window, std::shared_ptr<WindowMouseButtonReleasedListener> window_mouse_button_released_listener);

			/// @brief Registers a listener for a change of the mouse position on a specific window.
			void register_on_window_mouse_moved(EntityInstancePtr window, std::shared_ptr<WindowMouseMovedListener> window_mouse_moved_listener);

			/// @brief Registers a listener for mouse scroll on a specific window.
			void register_on_window_mouse_scrolled(EntityInstancePtr window, std::shared_ptr<WindowMouseScrolledListener> window_mouse_scrolled_listener);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.input.mouse";

		private:

			std::string get_window_name(EntityInstancePtr window);

			/// The factory for creating entity instance of type 'GLOBAL_MOUSE_BUTTON'.
			GlobalMouseButtonFactoryPtr global_mouse_button_factory;

			/// The log manager.
			LogManagerPtr log_manager;

			/// Signal, that the state of a mouse button has been changed on any window.
			SignalMouseButtonChanged signal_mouse_button_changed;

			/// Signal, that a mouse button has been pressed on any window.
			SignalMouseButtonPressed signal_mouse_button_pressed;

			/// Signal, that a mouse button has been released on any window.
			SignalMouseButtonReleased signal_mouse_button_released;

			/// Signal, that the state of a mouse button has been changed on a specific window.
			std::unordered_map<EntityInstancePtr, SignalMouseButtonChangedPtr> signal_window_mouse_button_changed;

			/// Signal, that a mouse button has been pressed on a specific window.
			std::unordered_map<EntityInstancePtr, SignalMouseButtonPressedPtr> signal_window_mouse_button_pressed;

			/// Signal, that a mouse button has been released on a specific window.
			std::unordered_map<EntityInstancePtr, SignalMouseButtonReleasedPtr> signal_window_mouse_button_released;

			/// Signal, that the mouse has been moved on a specific window.
			std::unordered_map<EntityInstancePtr, SignalMouseMovedPtr> signal_window_mouse_moved;

			/// Signal, that the mouse been scrolled on a specific window.
			std::unordered_map<EntityInstancePtr, SignalMouseScrolledPtr> signal_window_mouse_scrolled;

	};

}
}
