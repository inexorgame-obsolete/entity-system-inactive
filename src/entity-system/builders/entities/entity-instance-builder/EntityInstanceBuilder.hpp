// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "spdlog/spdlog.h"

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class EntityInstanceBuilder
    /// @brief Management of the loggers.
	class EntityInstanceBuilder : public enable_shared_from_this<EntityInstanceBuilder>
	{
		public:

			/// Constructor.
			EntityInstanceBuilder(
				shared_ptr<EntityInstanceManager> entity_instance_manager,
				shared_ptr<EntityTypeManager> entity_type_manager
			);

			/// Destructor.
			~EntityInstanceBuilder();

			/// Sets the name of the entity type to use.
			shared_ptr<EntityInstanceBuilder> type(string entity_type_name);

			/// Sets the entity type to use.
			shared_ptr<EntityInstanceBuilder> type(const ENT_TYPE& entity_type);

			/// Sets the uuid of the entity instance.
			shared_ptr<EntityInstanceBuilder> uuid(string entity_type_uuid);

			/// Sets the value of the attribute.
			shared_ptr<EntityInstanceBuilder> attribute(string attribute_name, DataContainer value);

			shared_ptr<EntityInstanceBuilder> attribute(string attribute_name, string value);

			shared_ptr<EntityInstanceBuilder> attribute(string attribute_name, int value);

            shared_ptr<EntityInstanceBuilder> attribute(string attribute_name, float value);

			/// Builds and returns the created entity instance.
			O_ENT_INST build();

		private:

			/// The entity instance manager
			shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The entity type manager
			shared_ptr<EntityTypeManager> entity_type_manager;

			/// The name of the entity type to use.
			string entity_type_name;

			/// The entity type to use.
			O_ENT_TYPE o_entity_type;

			/// The UUID of the new entity instance.
			string entity_instance_uuid;

			/// The attribute definitions.
			unordered_map<string, DataContainer> entity_instance_attributes;

	};


};
};
