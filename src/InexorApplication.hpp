#pragma once

#include "entity-system/EntitySystemModule.hpp"
#include "entity-system-rest/RestServer.hpp"
#include "entity-system-rest/RestServerLogger.hpp"

#include "type-system/TypeSystemModule.hpp"
#include "configuration/ConfigurationModule.hpp"
#include "visual-scripting/VisualScriptingSystemModule.hpp"
#include "scripting/ScriptingModule.hpp"
#include "logging/managers/LogManager.hpp"
#include "console/ConsoleModule.hpp"
#include "command/CommandModule.hpp"
#ifndef INEXOR_WITHOUT_CLIENT
#include "client/ClientModule.hpp"
#endif
#ifndef INEXOR_WITHOUT_SERVER
#include "server/ServerModule.hpp"
#endif

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
	using VisualScriptingSystemModulePtr = std::shared_ptr<visual_scripting::VisualScriptingSystemModule>;
	using ScriptingModulePtr = std::shared_ptr<scripting::ScriptingModule>;
	using ConsoleModulePtr = std::shared_ptr<console::ConsoleModule>;
	using CommandModulePtr = std::shared_ptr<command::CommandModule>;
#ifndef INEXOR_WITHOUT_CLIENT
	using ClientModulePtr = std::shared_ptr<client::ClientModule>;
#endif
#ifndef INEXOR_WITHOUT_SERVER
	using ServerModulePtr = std::shared_ptr<server::ServerModule>;
#endif
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
			/// @param rest_server The REST server module of the entity system.
			/// @param visual_scripting_system_module The visual scripting system module.
			/// @param scripting_module The scripting module.
			/// @param console_module The console module.
			/// @param command_module The command module.
			/// @param client_module The client module.
			/// @param server_module The server module.
			/// @param log_manager The log module.
			InexorApplication(
				EntitySystemModulePtr entity_system_module,
				TypeSystemModulePtr type_system_module,
				ConfigurationModulePtr configuration_module,
				RestServerPtr rest_server,
				VisualScriptingSystemModulePtr visual_scripting_system_module,
				ScriptingModulePtr scripting_module,
				ConsoleModulePtr console_module,
				CommandModulePtr command_module,
#ifndef INEXOR_WITHOUT_CLIENT
				ClientModulePtr client_module,
#endif
#ifndef INEXOR_WITHOUT_SERVER
				ServerModulePtr server_module,
#endif
				LogManagerPtr log_manager
			);

			// This is neccessary for constructor length greater than 10
			using boost_di_inject__ = boost::di::inject<
				EntitySystemModulePtr,
				TypeSystemModulePtr,
				ConfigurationModulePtr,
				RestServerPtr,
				VisualScriptingSystemModulePtr,
				ScriptingModulePtr,
				ConsoleModulePtr,
				CommandModulePtr,
#ifndef INEXOR_WITHOUT_CLIENT
				ClientModulePtr,
#endif
#ifndef INEXOR_WITHOUT_SERVER
				ServerModulePtr,
#endif
				LogManagerPtr
			>;

			/// Destructor.
			~InexorApplication();

			/// @brief Initializes the essential services of the Inexor application.
			/// @param argc The total number of parameters given to the application.
			/// @param argv An array of parameters given to the application.
			void pre_init(int argc, char* argv[]);

			/// @brief Initializes the Inexor application.
			void init();

			/// @brief Runs the application's main loop.
			/// @note The main loop will be aborted when this->running is set to false.
			void run();

			/// Shuts down the Inexor application.
			void shutdown();

			/// Restarts the Inexor application.
			void restart();

		private:

			/// The entity system of Inexor.
			EntitySystemModulePtr entity_system_module;

			/// The type system manager module.
			TypeSystemModulePtr type_system_module;

			/// The configuration manager module.
			ConfigurationModulePtr configuration_module;

			/// The REST server module of the entity system.
			RestServerPtr rest_server;

			/// The visual scripting system module.
			VisualScriptingSystemModulePtr visual_scripting_system_module;

			/// The scripting module.
			ScriptingModulePtr scripting_module;

			/// The console module.
			ConsoleModulePtr console_module;

			/// The command module.
			CommandModulePtr command_module;

#ifndef INEXOR_WITHOUT_CLIENT
			/// The client module.
			ClientModulePtr client_module;
#endif
#ifndef INEXOR_WITHOUT_SERVER
			/// The server module.
			ServerModulePtr server_module;
#endif

			/// The log manager.
			LogManagerPtr log_manager;

			/// The running state of the Inexor application.
			bool running;

			/// @brief Signal handler.
			/// @param signal_number ?
			void sighup_handler(const int signal_number);

			/// @brief Signal handler.
			/// @param signal_number ?
			void sigterm_handler(const int signal_number);

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

			/// Static instances of the Inexor application.
			static std::vector<InexorApplication *> instances;

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.app";

	};

}
