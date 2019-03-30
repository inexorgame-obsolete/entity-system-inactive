#pragma once

#include "mouse/managers/MouseInputManager.hpp"

namespace inexor {
namespace input {
namespace mouse {

	/// @class MouseInputModule
	/// @brief A module for handling Mouse input.
	class MouseInputModule
	{
		using MouseInputManagerPtr = std::shared_ptr<MouseInputManager>;

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param Mouse_input_manager The Mouse input manager.
			MouseInputModule(
				MouseInputManagerPtr mouse_input_manager
			);

			/// Destructor.
			~MouseInputModule();

			/// Initialization of the Mouse input module.
			void init();

		private:

			/// The Mouse input manager.
			MouseInputManagerPtr mouse_input_manager;

	};

}
}
}
