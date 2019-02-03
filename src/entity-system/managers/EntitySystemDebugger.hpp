// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "spdlog/spdlog.h"

#include "entity-system/listeners/entities/EntityTypeCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityTypeDeletedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"
#include "entity-system/listeners/relations/RelationTypeCreatedListener.hpp"
#include "entity-system/listeners/relations/RelationTypeDeletedListener.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class EntitySystemDebugger
    /// @brief Debugger for the entity system
	class EntitySystemDebugger
		: public enable_shared_from_this<EntitySystemDebugger>,
		  public EntityTypeCreatedListener,
		  public EntityTypeDeletedListener,
		  public EntityInstanceCreatedListener,
		  public EntityInstanceDeletedListener,
		  public RelationTypeCreatedListener,
		  public RelationTypeDeletedListener,
		  public RelationInstanceCreatedListener,
		  public RelationInstanceDeletedListener
	{
		public:

			/// Constructor.
			EntitySystemDebugger(
				shared_ptr<EntityTypeManager> entity_type_manager,
				shared_ptr<EntityInstanceManager> entity_instance_manager,
				shared_ptr<RelationTypeManager> relation_type_manager,
				shared_ptr<RelationInstanceManager> relation_instance_manager
			);

			/// Destructor.
			~EntitySystemDebugger();

			/// Initialization
			void init();

			void on_entity_type_created(ENT_TYPE entity_type);
			void on_entity_type_deleted(const xg::Guid& type_GUID);

			void on_entity_instance_created(ENT_INST entity_instance);
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			void on_relation_type_created(REL_TYPE relation_type);
			void on_relation_type_deleted(const xg::Guid& type_GUID);

			void on_relation_instance_created(REL_INST relation_instance);
			void on_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

		private:

			/// The entity type manager
			shared_ptr<EntityTypeManager> entity_type_manager;

			/// The entity instance manager
			shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The relation type manager
			shared_ptr<RelationTypeManager> relation_type_manager;

			/// The relation instance manager
			shared_ptr<RelationInstanceManager> relation_instance_manager;

	};


};
};
