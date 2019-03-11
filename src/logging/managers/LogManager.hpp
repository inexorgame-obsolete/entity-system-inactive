#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"

#include "type-system/factories/logger/LoggerFactory.hpp"
#include "type-system/providers/logger/LoggerEntityTypeProvider.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

namespace inexor {
namespace logging {

	using LoggerEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::LoggerEntityTypeProvider>;
	using LoggerFactoryPtr = std::shared_ptr<entity_system::type_system::LoggerFactory>;
	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class LogManager
    /// @brief Management of the loggers.
	class LogManager
		: public entity_system::EntityInstanceCreatedListener,
		  public entity_system::EntityInstanceDeletedListener,
		  public std::enable_shared_from_this<LogManager>
	{
		public:

			/// Constructor.
			LogManager(
				LoggerEntityTypeProviderPtr logger_entity_type_provider,
				LoggerFactoryPtr logger_factory,
				EntityInstanceManagerPtr entity_instance_manager
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

			/// Called when an entity instance of type ADD_INT has been created
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// Called when an entity instance of type ADD_INT has been deleted
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

		private:

			/// The logger sinks
			std::vector<spdlog::sink_ptr> sinks;

			/// The entity type provider
			LoggerEntityTypeProviderPtr logger_entity_type_provider;

			/// The entity type provider
			LoggerFactoryPtr logger_factory;

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The logger representation in the entity system
			std::unordered_map<std::string, EntityInstancePtr> logger_instances;

			/// The logger name of this service
			static constexpr char LOGGER_NAME[] = "inexor.logging.LogManager";

			/// The log file name
			static constexpr char LOG_FILE_NAME[] = "inexor.log";

	};

}
}
