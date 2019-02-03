// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "spdlog/spdlog.h"

#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class RelationInstanceBuilder
    /// @brief Builder for relation instances.
	class RelationInstanceBuilder : public enable_shared_from_this<RelationInstanceBuilder>
	{
		public:

			/// Constructor.
			RelationInstanceBuilder(
				shared_ptr<RelationInstanceManager> relation_instance_manager,
				shared_ptr<RelationTypeManager> relation_type_manager
			);

			/// Destructor.
			~RelationInstanceBuilder();

			/// Sets the name of the relation type to use.
			shared_ptr<RelationInstanceBuilder> type(string relation_type_name);

			/// Sets the relation type to use.
			shared_ptr<RelationInstanceBuilder> type(const REL_TYPE& relation_type);

			/// Sets the uuid of the relation instance.
			shared_ptr<RelationInstanceBuilder> uuid(string relation_type_uuid);

			/// Sets the source entity instance.
			shared_ptr<RelationInstanceBuilder> source(ENT_INST ent_instance_source);

			/// Sets the target entity instance.
			shared_ptr<RelationInstanceBuilder> target(ENT_INST ent_instance_target);

			/// Sets the value of the attribute.
			shared_ptr<RelationInstanceBuilder> attribute(string attribute_name, DataContainer value);

			shared_ptr<RelationInstanceBuilder> attribute(string attribute_name, string value);

			shared_ptr<RelationInstanceBuilder> attribute(string attribute_name, int value);

            shared_ptr<RelationInstanceBuilder> attribute(string attribute_name, float value);

			/// Builds and returns the created relation instance.
			O_REL_INST build();

		private:

			/// The relation instance manager
			shared_ptr<RelationInstanceManager> relation_instance_manager;

			/// The relation type manager
			shared_ptr<RelationTypeManager> relation_type_manager;

			/// The name of the relation type to use.
			string relation_type_name;

			/// The relation type to use.
			O_REL_TYPE o_relation_type;

			/// The UUID of the new relation instance.
			string relation_instance_uuid;

			/// The source entity instance.
			ENT_INST ent_instance_source;

			/// The target entity instance.
			ENT_INST ent_instance_target;

			/// The attribute definitions.
			unordered_map<string, DataContainer> relation_instance_attributes;

	};


};
};
