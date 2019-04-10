#pragma once

#include "entity-system/listeners/entities/EntityTypeCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityTypeDeletedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"
#include "entity-system/listeners/relations/RelationTypeCreatedListener.hpp"
#include "entity-system/listeners/relations/RelationTypeDeletedListener.hpp"
#include "entity-system/listeners/relations/RelationInstanceCreatedListener.hpp"
#include "entity-system/listeners/relations/RelationInstanceDeletedListener.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "logging/managers/LogManager.hpp"

#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;
	using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
	using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;
	using RelationInstanceManagerPtr = std::shared_ptr<RelationInstanceManager>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using RelationTypePtr = std::shared_ptr<RelationType>;
	using RelationInstancePtr = std::shared_ptr<RelationInstance>;

	/// @class EntitySystemDebugger
	/// @brief Debugger for the entity system.
	class EntitySystemDebugger
		: public EntityTypeCreatedListener,
		public EntityTypeDeletedListener,
		public EntityInstanceCreatedListener,
		public EntityInstanceDeletedListener,
		public RelationTypeCreatedListener,
		public RelationTypeDeletedListener,
		public RelationInstanceCreatedListener,
		public RelationInstanceDeletedListener,
		public std::enable_shared_from_this<EntitySystemDebugger>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.<br>
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// https://boost-experimental.github.io/di/user_guide/index.html
			/// @param entity_type_manager The entity type manager.
			/// @param entity_instance_manager The entity instance manager.
			/// @param relation_type_manager The relation type manager.
			/// @param relation_instance_manager The relation instance manager.
			/// @param log_manager The log manager.
			EntitySystemDebugger(
				EntityTypeManagerPtr entity_type_manager,
				EntityInstanceManagerPtr entity_instance_manager,
				RelationTypeManagerPtr relation_type_manager,
				RelationInstanceManagerPtr relation_instance_manager,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~EntitySystemDebugger();

			/// Initialization.
			void init();

			/// Initialization.
			void init_logger();

			void on_entity_type_created(EntityTypePtr entity_type);
			void on_entity_type_deleted(const xg::Guid& type_GUID);

			void on_entity_instance_created(EntityInstancePtr entity_instance);
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			void on_relation_type_created(RelationTypePtr relation_type);
			void on_relation_type_deleted(const xg::Guid& type_GUID);

			void on_relation_instance_created(RelationInstancePtr relation_instance);
			void on_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

		private:

			/// The entity type manager.
			EntityTypeManagerPtr entity_type_manager;

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The relation type manager.
			RelationTypeManagerPtr relation_type_manager;

			/// The relation instance manager.
			RelationInstanceManagerPtr relation_instance_manager;

			/// The log manager.
			LogManagerPtr log_manager;

			/// Logger.
			std::shared_ptr<spdlog::logger> logger;

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.entity.dbg";

	};

}
}
