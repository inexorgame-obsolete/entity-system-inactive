#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor {
namespace input {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class MouseInputManager
	/// @brief Management of the Mouse input data.
	class MouseInputManager
		: public std::enable_shared_from_this<MouseInputManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param log_manager The log manager.
			MouseInputManager(
				LogManagerPtr log_manager
			);

			/// Destructor.
			~MouseInputManager();

			/// Initialize the mouse input manager.
			void init();

			/// Shut down the mouse input manager.
			void shutdown();

			/// @brief The mouse position has been changed.
			void mouse_position_changed(EntityInstancePtr window, double xpos, double ypos);

			/// @brief The state of the mouse button has been changed.
			void mouse_button_changed(EntityInstancePtr window, int button, int action, int mods);

			/// @brief The state of the mouse scroll has been changed.
			void mouse_scroll_changed(EntityInstancePtr window, double xoffset, double yoffset);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.input.mouse";

		private:

			std::string get_window_name(EntityInstancePtr window);

			/// The log manager.
			LogManagerPtr log_manager;

	};

}
}
