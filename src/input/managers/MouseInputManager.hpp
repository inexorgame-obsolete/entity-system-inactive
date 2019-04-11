#pragma once

#include "logging/managers/LogManager.hpp"

struct GLFWwindow;

namespace inexor {
namespace input {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

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

			/// Initialize Mouse input module.
			void init();

			/// @brief
			/// @param
			void set_mouse_callback(GLFWwindow* window);

			/// @brief Callback method for mouse position.
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

			/// @brief ?
			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

			/// @brief ?
			static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

			/// The logger name of this service.
			/// WARNING: We can't use LOGGER_NAME inside of a static class method because it causes runtime errors!
			//static constexpr char LOGGER_NAME[] = "inexor.input.mouse.manager";

		private:

			/// The log manager.
			LogManagerPtr log_manager;

	};

}
}
