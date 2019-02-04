// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "spdlog/spdlog.h"

#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class RelationTypeBuilder
    /// @brief Builder for relation types.
	class RelationTypeBuilder : public enable_shared_from_this<RelationTypeBuilder>
	{
		public:

			/// Constructor.
			RelationTypeBuilder(
				shared_ptr<RelationTypeManager> relation_type_manager,
				shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager,
				shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
			);

			/// Destructor.
			~RelationTypeBuilder();

			/// Sets the name of the relation type.
			shared_ptr<RelationTypeBuilder> name(string relation_type_name);

			/// Sets the uuid of the relation type.
			shared_ptr<RelationTypeBuilder> uuid(string relation_type_uuid);

			/// Sets the source entity type.
			shared_ptr<RelationTypeBuilder> source(ENT_TYPE ent_type_source);

			/// Sets the target entity type.
			shared_ptr<RelationTypeBuilder> target(ENT_TYPE ent_type_target);

			/// Sets the uuid of the relation type.
			shared_ptr<RelationTypeBuilder> attribute(string attribute_name, DataType attribute_datatype, const EnumSet<Feature>& attribute_features);

			/// Builds and returns the created relation type.
			O_REL_TYPE build();

		private:

			/// The relation type manager
			shared_ptr<RelationTypeManager> relation_type_manager;

			/// The relation attribute instance manager
			shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager;

			/// The relation attribute instance manager
			shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager;

			/// The name of the new relation type.
			string relation_type_name;

			/// The UUID of the new relation type.
			string relation_type_uuid;

			/// The source entity type.
			ENT_TYPE ent_type_source;

			/// The target entity type.
			ENT_TYPE ent_type_target;

			/// The attribute definitions.
			unordered_map<string, DataType> relation_type_attributes;

			/// The attribute features.
			unordered_map<string, EnumSet<Feature>> relation_type_attribute_features;

	};


};
};
