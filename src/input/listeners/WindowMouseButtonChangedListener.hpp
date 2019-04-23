#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace input {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class WindowMouseButtonChangedListener
	/// @brief Listener for if a mouse button has been changed on a specific window.
	class WindowMouseButtonChangedListener
	{
		public:

			/// Called if a mouse button has been changed on a specific window.
			virtual void on_window_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods) = 0;

	};

}
}
