#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace input {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class KeyPressedListener
	/// @brief Listener for if a key has been pressed on any window.
	class KeyPressedListener
	{
		public:

			/// Called if a key has been pressed on any window.
			virtual void on_key_pressed(EntityInstancePtr window, int key, int scancode, int mods) = 0;

	};

}
}
