#include "CommandManager.hpp"

#include "entity-system/model/data/container/DataContainer.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace command {

	CommandManager::CommandManager(
		LogManagerPtr log_manager
	)
	{
		this->log_manager = log_manager;
	}

	CommandManager::~CommandManager()
	{
	}

	void CommandManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		// create_command("quit");
	}

	bool CommandManager::exists(std::string command_name)
	{
		// TODO: c++20: return config_names.contains(config_name);
		return commands.find(command_name) != commands.end();
	}

	void CommandManager::list()
	{
		spdlog::get(LOGGER_NAME)->info("Commands:");
		for(auto& it : commands)
		{
			spdlog::get(LOGGER_NAME)->info(
				"  [{}]",
				it.first
			);
		}
	}

}
}
