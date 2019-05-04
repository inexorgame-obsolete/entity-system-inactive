#pragma once

#include "console/managers/ConsoleManager.hpp"

namespace inexor {
namespace console {

	using ConsoleManagerPtr = std::shared_ptr<ConsoleManager>;

    /// @class ConsoleModule
    /// @brief This module provides consoles which can be used for multiple purposes.
    ///
    /// A console is the user interaction with a system within the Inexor
    /// Core. The system can be anything. In particular we need consoles for
    /// chats, ingame commands and for script interpreters on client and server
    /// side.
    ///
    /// The console consists of several components:
    /// - a prompt
    /// - an input line
    /// - a log buffer
    ///
	class ConsoleModule
	{
		public:

			/// @brief Constructs the console module.
            /// @note The dependencies of this class will be injected automatically.
            /// @param console_manager The console manager.
			ConsoleModule(
				ConsoleManagerPtr console_manager
			);

            /// Destructor.
			~ConsoleModule();

			/// Initializes the console module.
			void init();

			/// Shut down the console module.
			void shutdown();

		private:

			/// The console manager which manages the consoles.
			ConsoleManagerPtr console_manager;

	};

}
}
