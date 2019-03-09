// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/factories/logger/LoggerFactory.hpp"
#include "type-system/providers/logger/LoggerEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace logging {

	/// @class LogManager
    /// @brief Management of the loggers.
	class LogManager
	{
		public:

			/// Constructor.
			LogManager(
				shared_ptr<LoggerEntityTypeProvider> logger_entity_type_provider,
				shared_ptr<LoggerFactory> logger_factory,
				shared_ptr<EntityInstanceManager> entity_instance_manager
			);

			/// Destructor.
			~LogManager();

			/// Initialization of the loggers
			void init();

			/// Registers a logger
			void register_logger(std::string logger_name);

			/// Unregisters a logger
			void unregister_logger(std::string logger_name);

			/// Sets the log level for the given logger
			void set_level(std::string logger_name, spdlog::level::level_enum level);

			/// Returns the log level for the given logger
			spdlog::level::level_enum get_level(std::string logger_name);

		private:

			/// The logger sinks
			vector<spdlog::sink_ptr> sinks;

			/// The entity type provider
			shared_ptr<LoggerEntityTypeProvider> logger_entity_type_provider;

			/// The entity type provider
			shared_ptr<LoggerFactory> logger_factory;

			/// The entity instance manager
			shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The logger representation in the entity system
			unordered_map<std::string, shared_ptr<inexor::entity_system::EntityInstance>> logger_instances;

	};


};
};
