#include "CommandModule.hpp"

#include <utility>

namespace inexor::command {

CommandModule::CommandModule(CommandManangerPtr command_manager)
    : LifeCycleComponent(command_manager)
{
    this->command_manager = std::move(command_manager);
}

CommandModule::~CommandModule() = default;

std::string CommandModule::get_component_name()
{
    return "CommandModule";
}

} // namespace inexor::command
