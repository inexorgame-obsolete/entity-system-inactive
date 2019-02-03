// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/entities/entity-type-provider/EntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace logging {

	/// @class LoggerEntityTypeProvider
    /// @brief Provides the entity type LOGGER.
	class LoggerEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			LoggerEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"LOGGER",
				{
					{ "logger_name", DataType::STRING },
					{ "log_level", DataType::INT }
				}
			) {};

			/// Destructor.
			~LoggerEntityTypeProvider() {};

			// static string ATTTRIBUTE_LOGGER_NAME = "logger_name";

			// static string ATTTRIBUTE_LOG_LEVEL = "log_level";

	};


};
};
