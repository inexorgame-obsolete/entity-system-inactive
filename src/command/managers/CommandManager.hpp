#pragma once

#include "logging/managers/LogManager.hpp"

#include <unordered_map>

namespace inexor {
namespace command {

    /// Management of the commands.
	class CommandManager
	{
		using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
		using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
		using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
		using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
		using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

		public:

			CommandManager(
				LogManagerPtr log_manager
			);

			~CommandManager();

			/// Initialization of the command manager
			void init();

			/// Returns true, if the command exists.
			bool exists(std::string command);

			/// Creates a command.
			// EntityInstancePtr create(std::string command);

			/// Logs all commands.
			void list();

		private:

			/// The log manager
			LogManagerPtr log_manager;

			/// The names of the commands managed by the command manager
			std::unordered_map<std::string, EntityInstancePtr> commands;

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.cmd.manager";

	};

}
}
