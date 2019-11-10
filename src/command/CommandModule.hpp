#pragma once

#include "base/LifeCycleComponent.hpp"
#include "command/managers/CommandManager.hpp"

namespace inexor::command {

/// @class CommandModule
/// @brief The command module provides a system for executing commands.
class CommandModule : public LifeCycleComponent
{
    using CommandManangerPtr = std::shared_ptr<CommandManager>;

    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param command_manager The command manager.
    explicit CommandModule(CommandManangerPtr command_manager);

    /// Destructor.
    ~CommandModule();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The command manager.
    CommandManangerPtr command_manager;
};

} // namespace inexor::command
