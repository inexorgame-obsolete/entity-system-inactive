#pragma once

#include "command/managers/CommandManager.hpp"

namespace inexor {
namespace command {

    /// Module Command
	class CommandModule
	{
		using CommandManangerPtr = std::shared_ptr<CommandManager>;

		public:

			CommandModule(
				CommandManangerPtr command_manager
			);

			~CommandModule();

			/// Initialization of the command module
			void init();

		private:

			/// The command manager
			CommandManangerPtr command_manager;

	};

}
}
