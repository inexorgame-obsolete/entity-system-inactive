#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace input {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class WindowMouseButtonPressedListener
	/// @brief Listener for if a mouse button has been pressed on a specific window.
	class WindowMouseButtonPressedListener
	{
		public:

			/// Called if a mouse button has been pressed on a specific window.
			virtual void on_window_mouse_button_pressed(EntityInstancePtr window, int button, int mods) = 0;

	};

}
}
