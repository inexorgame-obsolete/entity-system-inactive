#pragma once

#include "logging/managers/LogManager.hpp"

namespace inexor {
namespace input {
namespace keyboard {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

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

			/// Initialize keyboard input module.
			void init();

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.i.k.manager";

		private:

			/// The log manager.
			LogManagerPtr log_manager;

    };

}
}
}
