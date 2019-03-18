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

	/// @class Inexor
	/// @brief The application container.
	class InexorApplication
	{

		public:

			/// Constructs the inexor application. The dependencies
			/// defined are automatically injected!
			/// @param entity_system_module
			/// @param type_system_module
			/// @param configuration_module
			/// @param rest_server
			/// @param entity_system_debugger
			/// @param visual_scripting_system_module
			/// @param log_manager
			/// @param renderer_manager
			InexorApplication(
				EntitySystemModulePtr entity_system_module,
				TypeSystemModulePtr type_system_module,
				ConfigurationModulePtr configuration_module,
				RestServerPtr rest_server,
				EntitySystemDebuggerPtr entity_system_debugger,
				VisualScriptingSystemModulePtr visual_scripting_system_module,
				LogManagerPtr log_manager,
				RendererModulePtr renderer_module,
				CommandModulePtr command_module
			);

			/// Destructor.
			/// Calls shutdown()
			~InexorApplication();

			/// Initializes the Inexor application.
			void init(int argc, char* argv[]);

			/// Run loop of the Inexor application. Blocks for ever (or until this->running was set to false)
			void run();

			/// Shuts down the Inexor application.
			void shutdown();

			/// Restarts the Inexor application, i.e. slightly improved wrapper around shutdown() and init();
			void restart();

			/// Registers a logger
			void register_logger(std::string logger_name);

			/// Getter for the entity system
			std::shared_ptr<entity_system::EntitySystemModule> get_entity_system();

			/// Getter for the rest server
			std::shared_ptr<entity_system::RestServer> get_rest_server();

		private:

            /// The entity system of Inexor
			EntitySystemModulePtr entity_system_module;

            /// The type system manager.
			TypeSystemModulePtr type_system_module;

            /// The configuration manager.
			ConfigurationModulePtr configuration_module;

            /// The REST server of the entity system
			RestServerPtr rest_server;

            /// The debugger of the entity system
			EntitySystemDebuggerPtr entity_system_debugger;

			/// The visual scripting system
			VisualScriptingSystemModulePtr visual_scripting_system_module;

            /// Management of the loggers
			LogManagerPtr log_manager;

            /// The rendering system
			RendererModulePtr renderer_module;

            /// The rendering system
			CommandModulePtr command_module;

			/// The running state of the Inexor application
			bool running;

            /// Signal handlers
            void sighup_handler(const int signal_number);
            void sigterm_handler(const int signal_number);
            void ready_handler(Service&);

            static void call_sighup_handlers(int signal_number)
            {
            	for (InexorApplication* instance : InexorApplication::instances)
            	{
            		std::mem_fn(&InexorApplication::sighup_handler)(instance, signal_number);
            	}
			}

            static void call_sigterm_handlers(int signal_number)
            {
            	for (InexorApplication* instance : InexorApplication::instances)
            	{
            		std::mem_fn(&InexorApplication::sigterm_handler)(instance, signal_number);
            	}
			}

            static void call_ready_handlers(Service& service)
            {
            	for (InexorApplication* instance : InexorApplication::instances)
            	{
            		std::mem_fn(&InexorApplication::ready_handler)(instance, service);
            	}
			}

			/// Static instances of the Inexor application
			static std::vector<InexorApplication *> instances;

			/// The logger name of this service
			static constexpr char LOGGER_NAME[] = "inexor.app";

	};

}
