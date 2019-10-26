#include "CommandModule.hpp"

#include <utility>

namespace inexor::command {

CommandModule::CommandModule(CommandManangerPtr command_manager)
{
    this->command_manager = std::move(command_manager);
}

CommandModule::~CommandModule() = default;

void CommandModule::init()
{
    command_manager->init();
}

} // namespace inexor::command
