#include "CommandModule.hpp"

namespace inexor {
namespace command {

	CommandModule::CommandModule(
		CommandManangerPtr command_manager
	)
	{
		this->command_manager = command_manager;
	}

	CommandModule::~CommandModule()
	{
	}

	void CommandModule::init()
	{
		command_manager->init();
	}

}
}
