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

#include "entity-system/EntitySystem.hpp"
#include "entity-system-rest/RestServer.hpp"
#include "entity-system-example/ColorManager.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
using namespace spdlog;

namespace inexor {

	/// @class Inexor
	/// @brief The application container.
	class Inexor
	{
		private:

            /// 
            std::shared_ptr<inexor::entity_system::EntitySystem> entity_system;


            /// 
			std::shared_ptr<inexor::entity_system::RestServer> rest_server;


            /// 
            int rest_server_port = 8080;

        public:

			/// Constructor.
			Inexor();


			/// Destructor.
			~Inexor();


            /// 
			std::shared_ptr<inexor::entity_system::EntitySystem> get_entity_system();


            /// 
			std::shared_ptr<inexor::entity_system::RestServer> get_rest_server();

			///

	};


};
