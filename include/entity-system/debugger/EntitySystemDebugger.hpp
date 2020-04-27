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

namespace inexor::entity_system {

	/// These using instructions help to shorten the following code.
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
	/// @brief A Debugger for the entity system.
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

			/// @brief Destructor.
			~EntitySystemDebugger();

			/// @brief Initialization.
			void init();

			/// @brief Logger initialization.
			void init_logger();

			/// @brief Callback for creation of entity types.
			/// @param ent_type The entity type which was created.
			/// @TODO Change to const EntityTypePtr& ?
			void on_entity_type_created(EntityTypePtr ent_type) override;

			/// @brief Callback for deletion of entity types.
			/// @param ent_type_GUID The GUID of the entity type which was deleted.
			void on_entity_type_deleted(const xg::Guid& ent_type_GUID) override;

			/// @brief Callback for creation of entity instances.
			/// @param ent_inst The entity instance which was created.
			/// @TODO Change to const EntityInstancePtr& ?
			void on_entity_instance_created(EntityInstancePtr ent_inst) override;

			/// @brief Callback for deletion of entity instances.
			/// @param ent_type_GUID The GUID of the entity type which was deleted.
			/// @param ent_inst_GUID The GUID of the entity instance which was deleted.
			void on_entity_instance_deleted(const xg::Guid& ent_type_GUID, const xg::Guid& ent_inst_GUID) override;

			/// @brief Callback for creation of relation types.
			/// @param rel_type The relation type which was created.
			/// @TODO Change to const RelationTypePtr& ?
			void on_relation_type_created(RelationTypePtr rel_type) override;

			/// @brief Callback for deletion of relation types.
			/// @param rel_type_GUID The GUID of the relation type which was deleted.
			void on_relation_type_deleted(const xg::Guid& rel_type_GUID) override;

			/// @brief Callback for creation of relation instances.
			/// @param rel_inst The relation instance which was created.
			/// @TODO Change to const RelationInstancePtr& ?
			void on_relation_instance_created(RelationInstancePtr rel_inst) override;

			/// @brief Callback for deletion of relation instances.
			/// @param rel_type_GUID The GUID of the relation type of which a relation instance was deleted.
			/// @param rel_inst_GUID The GUID of the relation instance which was deleted.
			void on_relation_instance_deleted(const xg::Guid& rel_type_GUID, const xg::Guid& rel_inst_GUID) override;

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

			/// The mutex of this class.
			std::mutex entity_system_debugger_mutex;

	};

}
