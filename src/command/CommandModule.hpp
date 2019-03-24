#pragma once

#include "command/managers/CommandManager.hpp"

namespace inexor {
namespace command {

    /// @class CommandModule
    /// @brief Command module.
	class CommandModule
	{
		using CommandManangerPtr = std::shared_ptr<CommandManager>;

		public:

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
            /// @param command_manager The command manager.
			CommandModule(
				CommandManangerPtr command_manager
			);

            /// Destructor.
			~CommandModule();

			/// Initialization of the command module.
			void init();

		private:

			/// The command manager.
			CommandManangerPtr command_manager;

	};

}
}
