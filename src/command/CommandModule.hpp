#pragma once

#include "command/managers/CommandManager.hpp"

namespace inexor::command {

/// @class CommandModule
/// @brief The command module provides a system for executing commands.
class CommandModule
{
    using CommandManangerPtr = std::shared_ptr<CommandManager>;

    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param command_manager The command manager.
    explicit CommandModule(CommandManangerPtr command_manager);

    /// Destructor.
    ~CommandModule();

    /// Initialization of the command module.
    void init();

    private:
    /// The command manager.
    CommandManangerPtr command_manager;
};

} // namespace inexor::command
