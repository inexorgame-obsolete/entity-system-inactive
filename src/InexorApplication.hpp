#pragma once

#include "entity-system/EntitySystemModule.hpp"
#include "entity-system/managers/EntitySystemDebugger.hpp"
#include "entity-system-rest/RestServer.hpp"
#include "entity-system-rest/RestServerLogger.hpp"

#include "type-system/TypeSystemModule.hpp"
#include "configuration/ConfigurationModule.hpp"
#include "visual-scripting/VisualScriptingSystemModule.hpp"
#include "logging/managers/LogManager.hpp"
#include "renderer/RendererModule.hpp"
#include "command/CommandModule.hpp"
#include "keyboard/KeyboardInputModule.hpp"

#include <memory>
#include <cstdlib>
#include <restbed>
#include <csignal>
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
	using RestServerPtr = std::shared_ptr<entity_system::RestServer>;
	using EntitySystemDebuggerPtr = std::shared_ptr<entity_system::EntitySystemDebugger>;
	using VisualScriptingSystemModulePtr = std::shared_ptr<visual_scripting::VisualScriptingSystemModule>;
	using LogManagerPtr = std::shared_ptr<logging::LogManager>;
	using RendererModulePtr = std::shared_ptr<renderer::RendererModule>;
	using CommandModulePtr = std::shared_ptr<command::CommandModule>;
    using KeyboardInputModulePtr = std::shared_ptr<input::keyboard::KeyboardInputModule>;

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
			/// @param rest_server The REST server module of the entity system.
			/// @param entity_system_debugger The debugger of the entity system module.
			/// @param visual_scripting_system_module The visual scripting system module.
			/// @param log_manager The log module.
			/// @param renderer_manager The rendering module.
            /// @param CommandModulePtr The command module.
            /// @param KeyboardInputModulePtr The keyboard input module.
			InexorApplication(
				EntitySystemModulePtr entity_system_module,
				TypeSystemModulePtr type_system_module,
				ConfigurationModulePtr configuration_module,
				RestServerPtr rest_server,
				EntitySystemDebuggerPtr entity_system_debugger,
				VisualScriptingSystemModulePtr visual_scripting_system_module,
				LogManagerPtr log_manager,
				RendererModulePtr renderer_module,
				CommandModulePtr command_module,
                KeyboardInputModulePtr keyboard_input_module
			);

			/// Destructor.
			~InexorApplication();

			/// @brief Initializes the Inexor application.
            /// @param argc The total number of parameters given to the application.
            /// @param argv An array of parameters given to the application.
			void init(int argc, char* argv[]);

            /// @brief Runs the application's main loop.
            /// @note The main loop will be aborted when this->running is set to false.
			void run();

			/// Shuts down the Inexor application.
			void shutdown();

			/// Restarts the Inexor application.
			void restart();

			/// @brief Registers a logger.
            /// @param logger_name The name of the logger.
			void register_logger(std::string logger_name);

			/// Get method for the entity system.
			std::shared_ptr<entity_system::EntitySystemModule> get_entity_system();

			/// Get method for the rest server.
			std::shared_ptr<entity_system::RestServer> get_rest_server();

		private:

            /// The entity system of Inexor.
			EntitySystemModulePtr entity_system_module;

            /// The type system manager module.
			TypeSystemModulePtr type_system_module;

            /// The configuration manager module.
			ConfigurationModulePtr configuration_module;

            /// The REST server module of the entity system.
			RestServerPtr rest_server;

            /// The debugger of the entity system module.
			EntitySystemDebuggerPtr entity_system_debugger;

			/// The visual scripting system module.
			VisualScriptingSystemModulePtr visual_scripting_system_module;

            /// The log manager.
			LogManagerPtr log_manager;

            /// The rendering module.
			RendererModulePtr renderer_module;
            
            /// The command module.
			CommandModulePtr command_module;

            /// The keyboard input module.
            KeyboardInputModulePtr keyboard_input_module;

			/// The running state of the Inexor application.
			bool running;

            /// @brief Signal handler.
            /// @param signal_number ?
            void sighup_handler(const int signal_number);

            /// @brief Signal handler.
            /// @param signal_number ?
            void sigterm_handler(const int signal_number);

            /// ?
            void ready_handler(Service&);

            /// ?
            /// @param signal_number ?
            static void call_sighup_handlers(int signal_number)
            {
            	for (InexorApplication* instance : InexorApplication::instances)
            	{
            		std::mem_fn(&InexorApplication::sighup_handler)(instance, signal_number);
            	}
			}

            /// ?
            /// @param signal_number ?
            static void call_sigterm_handlers(int signal_number)
            {
            	for (InexorApplication* instance : InexorApplication::instances)
            	{
            		std::mem_fn(&InexorApplication::sigterm_handler)(instance, signal_number);
            	}
			}
            
            /// ?
            /// @param service ?
            static void call_ready_handlers(Service& service)
            {
            	for (InexorApplication* instance : InexorApplication::instances)
            	{
            		std::mem_fn(&InexorApplication::ready_handler)(instance, service);
            	}
			}

			/// Static instances of the Inexor application.
			static std::vector<InexorApplication *> instances;

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.app";

	};

}
