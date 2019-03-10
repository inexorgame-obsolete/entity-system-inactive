#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "LOGGER". The LOGGER logs
	class LoggerEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the LOGGER entity type
			LoggerEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ LOGGER_NAME, { DataType::STRING, 1 << Feature::OUTPUT } },
					{ LOG_LEVEL, { DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ LOG_MESSAGE, { DataType::STRING, 1 << Feature::INPUT } }
				}
			) {};

			~LoggerEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "LOGGER";

			/// The name of the attribute logger_name
			static constexpr char LOGGER_NAME[] = "logger_name";

			/// The name of the attribute log_level
			static constexpr char LOG_LEVEL[] = "log_level";

			/// The name of the attribute log_message
			static constexpr char LOG_MESSAGE[] = "log_message";

	};

}
}
}
