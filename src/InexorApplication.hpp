// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

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

#include "entity-system/EntitySystem.hpp"
#include "entity-system/managers/EntitySystemDebugger.hpp"
#include "entity-system-rest/RestServer.hpp"
#include "entity-system-rest/RestServerLogger.hpp"
#include "entity-system-example/ColorManager.hpp"

#include "type-system/managers/TypeSystemManager.hpp"
#include "configuration/ConfigurationModule.hpp"
#include "visual-scripting/VisualScriptingSystem.hpp"
#include "logging/managers/LogManager.hpp"
#include "renderer/managers/RendererManager.hpp"



#define LOGGER_NAME "inexor.app"

namespace inexor {

	/// @class Inexor
	/// @brief The application container.
	class InexorApplication
	{

		public:

			/// Constructor.
			/// The dependencies defined are automatically injected!
			InexorApplication(
				std::shared_ptr<inexor::entity_system::EntitySystem> entity_system,
				std::shared_ptr<inexor::entity_system::type_system::TypeSystemManager> type_system_manager,
				std::shared_ptr<inexor::configuration::ConfigurationModule> configuration_module,
				std::shared_ptr<inexor::entity_system::RestServer> rest_server,
				std::shared_ptr<inexor::entity_system::EntitySystemDebugger> entity_system_debugger,
				std::shared_ptr<inexor::visual_scripting::VisualScriptingSystem> visual_scripting_system,
				std::shared_ptr<inexor::logging::LogManager> log_manager,
				std::shared_ptr<inexor::renderer::RendererManager> renderer_manager
			);


			/// Destructor.
			/// Calls shutdown()
			~InexorApplication();

			/// Initializes the Inexor application.
			void init();

			/// Run loop of the Inexor application. Blocks for ever (or until this->running was set to false)
			void run();

			/// Shuts down the Inexor application.
			void shutdown();

			/// Restarts the Inexor application, i.e. slightly improved wrapper around shutdown() and init();
			void restart();

			/// Registers a logger
			void register_logger(std::string logger_name);

			/// Getter for the entity system
			std::shared_ptr<inexor::entity_system::EntitySystem> get_entity_system();

			/// Getter for the rest server
			std::shared_ptr<inexor::entity_system::RestServer> get_rest_server();

		private:

            /// The entity system of Inexor
            std::shared_ptr<inexor::entity_system::EntitySystem> entity_system;

            /// The type system manager.
            std::shared_ptr<inexor::entity_system::type_system::TypeSystemManager> type_system_manager;

            /// The configuration manager.
            std::shared_ptr<inexor::configuration::ConfigurationModule> configuration_module;

            /// The REST server of the entity system
			std::shared_ptr<inexor::entity_system::RestServer> rest_server;

            /// The debugger of the entity system
			std::shared_ptr<inexor::entity_system::EntitySystemDebugger> entity_system_debugger;

			/// The visual scripting system
			std::shared_ptr<inexor::visual_scripting::VisualScriptingSystem> visual_scripting_system;

            /// Management of the loggers
			std::shared_ptr<inexor::logging::LogManager> log_manager;

            /// Management of the renderers
			std::shared_ptr<inexor::renderer::RendererManager> renderer_manager;

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

	};


}
