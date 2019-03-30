#pragma once

#include "keyboard/managers/KeyboardInputManager.hpp"

namespace inexor {
namespace input {
namespace keyboard {

	/// @class KeyboardInputModule
	/// @brief A module for handling keyboard input.
	class KeyboardInputModule
	{
		using KeyboardInputManagerPtr = std::shared_ptr<KeyboardInputManager>;

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param keyboard_input_manager The keyboard input manager.
			KeyboardInputModule(
			KeyboardInputManagerPtr keyboard_input_manager
			);

			/// Destructor.
			~KeyboardInputModule();

			/// Initialization of the keyboard input module.
			void init();

		private:

			/// The keyboard input manager.
			KeyboardInputManagerPtr keyboard_input_manager;

	};

}
}
}
