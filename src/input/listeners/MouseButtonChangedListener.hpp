#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace input {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class MouseButtonChangedListener
	/// @brief Listener for if a mouse button has been changed on any window.
	class MouseButtonChangedListener
	{
		public:

			/// Called if a mouse button has been changed on any window.
			virtual void on_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods) = 0;

	};

}
}
