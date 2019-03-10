#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logger/LoggerEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using LoggerEntityTypeProviderPtr = std::shared_ptr<LoggerEntityTypeProvider>;

    /// Factory for creating entity instances of type LOGGER.
	class LoggerFactory
	{
		public:

			/// Constructor.
			LoggerFactory(
				LoggerEntityTypeProviderPtr logger_entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			/// Destructor.
			~LoggerFactory();

			/// Initializes the factory.
			void init();

			/// Initialization of the loggers
			EntityInstancePtrOpt create_instance();

			/// Creates an instance and sets the given name
			EntityInstancePtrOpt create_instance(std::string logger_name);

			/// Creates an instance and sets the given name
			EntityInstancePtrOpt create_instance(std::string logger_name, spdlog::level::level_enum log_level);

			/// Creates multiple instances
			std::vector<EntityInstancePtr> create_instances(int count);

		private:

			/// Provides the entity type LOGGER.
			LoggerEntityTypeProviderPtr logger_entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
