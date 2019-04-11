#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor {
namespace input {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class KeyboardInputManager
	/// @brief Management of the keyboard input data.
	class KeyboardInputManager
		: public std::enable_shared_from_this<KeyboardInputManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param log_manager The log manager.
			KeyboardInputManager(
				LogManagerPtr log_manager
			);

			/// Destructor.
			~KeyboardInputManager();

			/// Initialize the keyboard input module.
			void init();

			/// Shut down the keyboard input manager.
			void shutdown();

			/// @brief Called if the state of a key has been changed.
			/// @param window The entity instance of type 'WINDOW'.
			/// @param key
			/// @param scancode
			/// @param action
			/// @param mods
			void key_changed(EntityInstancePtr window, int key, int scancode, int action, int mods);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.input.keyboard";

		private:

			std::string get_window_name(EntityInstancePtr window);

			/// The log manager.
			LogManagerPtr log_manager;

	};

}
}
