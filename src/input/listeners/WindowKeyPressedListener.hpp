#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace input {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class WindowKeyPressedListener
	/// @brief Listener for if a key has been pressed on a specific window.
	class WindowKeyPressedListener
	{
		public:

			/// Called if a key has been pressed on a specific window.
			virtual void on_window_key_pressed(EntityInstancePtr window, int key, int scancode, int mods) = 0;

	};

}
}
