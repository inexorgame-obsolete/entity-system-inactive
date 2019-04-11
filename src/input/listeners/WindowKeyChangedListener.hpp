#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace input {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class WindowKeyChangedListener
	/// @brief Listener for key changes (pressed and released) on a specific window.
	class WindowKeyChangedListener
	{
		public:

			/// Called if a key has been changed on a specific window.
			virtual void on_key_changed(EntityInstancePtr window, int key, int scancode, int action, int mods) = 0;

	};

}
}
