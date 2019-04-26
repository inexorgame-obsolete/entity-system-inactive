#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace input {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class PathDroppedListener
	/// @brief Listener for path drops on any window.
	class PathDroppedListener
	{
		public:

			/// Called if a path has been dropped on any window.
			virtual void on_path_dropped(EntityInstancePtr window, std::vector<std::string> paths) = 0;

	};

}
}
