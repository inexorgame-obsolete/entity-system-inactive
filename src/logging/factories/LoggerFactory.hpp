// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-builder-manager/EntityInstanceBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "logging/providers/LoggerEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace logging {

	/// @class LoggerFactory
    /// @brief Management of the loggers.
	class LoggerFactory
	{
		public:

			/// Constructor.
			LoggerFactory(
				shared_ptr<LoggerEntityTypeProvider> logger_entity_type_provider,
				shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager,
				shared_ptr<EntityInstanceManager> entity_instance_manager
			);

			/// Destructor.
			~LoggerFactory();

			/// Initialization of the loggers
			O_ENT_INST create_instance();

			/// Creates an instance and sets the given name
			O_ENT_INST create_instance(string logger_name);

			/// Creates an instance and sets the given name
			O_ENT_INST create_instance(string logger_name, spdlog::level::level_enum log_level);

			/// Creates multiple instances
			vector<ENT_INST> create_instances(int count);

		private:

			/// The entity type provider
			shared_ptr<LoggerEntityTypeProvider> logger_entity_type_provider;

			/// The entity instance manager
			shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager;

			/// The entity instance manager
			shared_ptr<EntityInstanceManager> entity_instance_manager;

	};


};
};
