// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

#include "../entity-system/EntitySystem.hpp"

namespace inexor {
namespace logging {

	/// @class LogManager
    /// @brief Management of the loggers.
	class LogManager
	{
		public:

			/// Constructor.
			LogManager(std::shared_ptr<inexor::entity_system::EntitySystem> entity_system);

			/// Destructor.
			~LogManager();

			/// Initialization of the loggers
			void init();

			/// Registers a logger
			void register_logger(std::string logger_name);

		private:

			/// The logger sinks
			std::vector<spdlog::sink_ptr> sinks;

			/// The inexor entity system
			std::shared_ptr<inexor::entity_system::EntitySystem> entity_system;

	};


};
};
