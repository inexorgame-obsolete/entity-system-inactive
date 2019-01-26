// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

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
				shared_ptr<EntityTypeManager> entity_type_manager,
				shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager,
				shared_ptr<EntityInstanceManager> entity_instance_manager,
				shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
			);

			/// Destructor.
			~LogManager();

			/// Initialization of the loggers
			void init();

			/// Registers a logger
			void register_logger(std::string logger_name);

			/// Unregisters a logger
			void unregister_logger(std::string logger_name);

		private:

			/// The logger sinks
			vector<spdlog::sink_ptr> sinks;

			/// The entity type manager
			shared_ptr<EntityTypeManager> entity_type_manager;

			/// The entity attribute instance manager
			shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager;

			/// The entity instance manager
			shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The entity attribute instance manager
			shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;

			/// The entity type LOGGER
			shared_ptr<inexor::entity_system::EntityType> entity_type_logger;

			/// The entity type LOGGER
			shared_ptr<EntityAttributeType> attr_logger_name;
	};


};
};
