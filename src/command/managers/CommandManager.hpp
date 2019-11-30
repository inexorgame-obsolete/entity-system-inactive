#pragma once

#include <unordered_map>

#include "base/LifeCycleComponent.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor::command {

/// @class CommandManager
/// @brief Management of the commands.
class CommandManager : public LifeCycleComponent
{
    using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
    using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
    using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
    using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
    using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param log_manager The log manager.
    explicit CommandManager(LogManagerPtr log_manager);

    /// Destructor.
    ~CommandManager();

    /// Initializes the logger.
    void init() override;

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Returns true, if the command exists.
    /// @param command The name of the command.
    /// @return <b>true</b> if the command exists, <b>false</b> otherwise.
    bool exists(const std::string& command);

    /// Creates a command.
    /// @param command The name of the command.
    // EntityInstancePtr create(std::string command);

    /// Logs all commands.
    void list();

    private:
    /// The log manager.
    LogManagerPtr log_manager;

    /// The names of the commands managed by the command manager.
    std::unordered_map<std::string, EntityInstancePtr> commands;

    /// The logger name of this processor.
    static constexpr char LOGGER_NAME[] = "inexor.cmd.manager";
};

} // namespace inexor::command
