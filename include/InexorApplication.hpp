#pragma once

#include "entity-system/EntitySystemModule.hpp"
#include "entity-system/debugger/EntitySystemDebugger.hpp"

#include "client/ClientModule.hpp"
#include "command/CommandModule.hpp"
#include "configuration/ConfigurationModule.hpp"
#include "logging/managers/LogManager.hpp"
#include "type-system/TypeSystemModule.hpp"
#include "visual-scripting/VisualScriptingSystemModule.hpp"

#include <csignal>
#include <cstdlib>
#include <memory>
#include <sys/types.h>

#ifdef _WIN32
#include <process.h>
#else
#include <unistd.h>
#endif

#include <boost/di.hpp>

#include "spdlog/spdlog.h"

namespace inexor {

using EntitySystemModulePtr = std::shared_ptr<entity_system::EntitySystemModule>;
using TypeSystemModulePtr = std::shared_ptr<entity_system::type_system::TypeSystemModule>;
using ConfigurationModulePtr = std::shared_ptr<configuration::ConfigurationModule>;
using EntitySystemDebuggerPtr = std::shared_ptr<entity_system::EntitySystemDebugger>;
using VisualScriptingSystemModulePtr = std::shared_ptr<visual_scripting::VisualScriptingSystemModule>;
using CommandModulePtr = std::shared_ptr<command::CommandModule>;
using ClientModulePtr = std::shared_ptr<client::ClientModule>;
using LogManagerPtr = std::shared_ptr<logging::LogManager>;

/// @class Inexor
/// @brief The application container.
class InexorApplication
{
    public:
    /// @brief Constructs the Inexor application.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_system_module The entity system of Inexor.
    /// @param type_system_module The type system manager.
    /// @param configuration_module The configuration manager module.
    /// @param entity_system_debugger The debugger of the entity system module.
    /// @param visual_scripting_system_module The visual scripting system module.
    /// @param log_manager The log module.
    /// @param renderer_manager The rendering module.
    /// @param command_module The command module.
    /// @param audio_module The audio module.
    InexorApplication(EntitySystemModulePtr entity_system_module, TypeSystemModulePtr type_system_module, ConfigurationModulePtr configuration_module, EntitySystemDebuggerPtr entity_system_debugger,
                      VisualScriptingSystemModulePtr visual_scripting_system_module, CommandModulePtr command_module, ClientModulePtr client_module, LogManagerPtr log_manager);

    /// Destructor.
    ~InexorApplication();

    /// @brief Initializes the essential services of the Inexor application.
    /// @param argc The total number of parameters given to the application.
    /// @param argv An array of parameters given to the application.
    void pre_init(int argc, char *argv[]);

    /// @brief Initializes the Inexor application.
    void init();

    /// @brief Runs the application's main loop.
    /// @note The main loop will be aborted when this->running is set to false.
    void run();

    /// Shuts down the Inexor application.
    void destroy();

    /// Shuts down the Inexor application.
    void post_destroy();

    /// Restarts the Inexor application.
    void restart();

    private:
    /// The entity system of Inexor.
    EntitySystemModulePtr entity_system_module;

    /// The type system manager module.
    TypeSystemModulePtr type_system_module;

    /// The configuration manager module.
    ConfigurationModulePtr configuration_module;

    /// The debugger of the entity system module.
    EntitySystemDebuggerPtr entity_system_debugger;

    /// The visual scripting system module.
    VisualScriptingSystemModulePtr visual_scripting_system_module;

    /// The command module.
    CommandModulePtr command_module;

    /// The client module.
    ClientModulePtr client_module;

    /// The log manager.
    LogManagerPtr log_manager;

    /// The running state of the Inexor application.
    bool running;

    /// @brief Signal handler.
    /// @param signal_number ?
    void sighup_handler(int signal_number);

    /// @brief Signal handler.
    /// @param signal_number ?
    void sigterm_handler(int signal_number);

    /// ?
    /// @param signal_number ?
    static void call_sighup_handlers(int signal_number)
    {
        for (InexorApplication *instance : InexorApplication::instances)
        {
            std::mem_fn (&InexorApplication::sighup_handler)(instance, signal_number);
        }
    }

    /// ?
    /// @param signal_number ?
    static void call_sigterm_handlers(int signal_number)
    {
        for (InexorApplication *instance : InexorApplication::instances)
        {
            std::mem_fn (&InexorApplication::sigterm_handler)(instance, signal_number);
        }
    }

    /// Static instances of the Inexor application.
    static std::vector<InexorApplication *> instances;

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.app";
};

} // namespace inexor
