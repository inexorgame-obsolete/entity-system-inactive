#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace input {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class MouseButtonPressedListener
	/// @brief Listener for if a mouse button has been pressed on any window.
	class MouseButtonPressedListener
	{
		public:

			/// Called if a mouse button has been pressed on any window.
			virtual void on_mouse_button_pressed(EntityInstancePtr window, int button, int mods) = 0;

	};

}
}
