#pragma once

#include "input/managers/KeyboardInputManager.hpp"
#include "input/managers/MouseInputManager.hpp"

namespace inexor {
namespace input {

	/// @class InputModule
	/// @brief A module for handling input (keyboard, mouse, joystick, gamepad).
	class InputModule
	{
		using KeyboardInputManagerPtr = std::shared_ptr<KeyboardInputManager>;
		using MouseInputManagerPtr = std::shared_ptr<MouseInputManager>;

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param keyboard_input_manager The keyboard input manager.
			InputModule(
				KeyboardInputManagerPtr keyboard_input_manager,
				MouseInputManagerPtr mouse_input_manager
			);

			/// Destructor.
			~InputModule();

			/// Initialization of the input module.
			void init();

		private:

			/// The keyboard input manager.
			KeyboardInputManagerPtr keyboard_input_manager;

			/// The mouse input manager.
			MouseInputManagerPtr mouse_input_manager;

	};

}
}
