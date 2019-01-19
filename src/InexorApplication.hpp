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

#include "entity-system/EntitySystem.hpp"
#include "entity-system-rest/RestServer.hpp"
#include "entity-system-rest/RestServerLogger.hpp"
#include "entity-system-example/ColorManager.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

using namespace spdlog;

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
				std::shared_ptr<inexor::entity_system::RestServer> rest_server
			);


			/// Destructor.
			/// Calls shutdown()
			~InexorApplication();

			/// Starts the Inexor application.
			void start();

			/// Run loop of the Inexor application.
			void run();

			/// Shuts down the Inexor application.
			void shutdown();

			/// Restarts the Inexor application.
			void restart();

			/// Getter for the entity system
			std::shared_ptr<inexor::entity_system::EntitySystem> get_entity_system();

			/// Getter for the rest server
			std::shared_ptr<inexor::entity_system::RestServer> get_rest_server();

		private:

            /// The entity system of Inexor
            std::shared_ptr<inexor::entity_system::EntitySystem> entity_system;

            /// The REST server of the entity system
			std::shared_ptr<inexor::entity_system::RestServer> rest_server;

			/// The running state of the Inexor application
			bool running = false;

            /// Signal handlers
            void sighup_handler(const int signal_number);
            void sigterm_handler(const int signal_number);
            void ready_handler(Service&);

            static void call_sighup_handlers(int signal_number)
            {
				std::for_each(InexorApplication::instances.begin(), InexorApplication::instances.end(), std::bind2nd(std::mem_fun(&InexorApplication::sighup_handler), signal_number));
			}

            static void call_sigterm_handlers(int signal_number)
            {
				std::for_each(InexorApplication::instances.begin(), InexorApplication::instances.end(), std::bind2nd(std::mem_fun(&InexorApplication::sighup_handler), signal_number));
			}

            static void call_ready_handlers(Service& service)
            {
				std::for_each(InexorApplication::instances.begin(), InexorApplication::instances.end(), std::bind2nd(std::mem_fun(&InexorApplication::ready_handler), service));
			}

			/// Static instances of the Inexor application
			static std::vector<InexorApplication *> instances;

	};


};
