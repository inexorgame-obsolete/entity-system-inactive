// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "spdlog/spdlog.h"

#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class EntityTypeBuilder
    /// @brief Management of the loggers.
	class EntityTypeBuilder : public enable_shared_from_this<EntityTypeBuilder>
	{
		public:

			/// Constructor.
			EntityTypeBuilder(
				shared_ptr<EntityTypeManager> entity_type_manager,
				shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager,
				shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
			);

			/// Destructor.
			~EntityTypeBuilder();

			/// Sets the name of the entity type.
			shared_ptr<EntityTypeBuilder> name(string entity_type_name);

			/// Sets the uuid of the entity type.
			shared_ptr<EntityTypeBuilder> uuid(string entity_type_uuid);

			/// Sets the uuid of the entity type.
			shared_ptr<EntityTypeBuilder> attribute(string attribute_name, ENTSYS_DATA_TYPE attribute_datatype);

			/// Builds and returns the created entity type.
			O_ENT_TYPE build();

		private:

			/// The entity type manager
			shared_ptr<EntityTypeManager> entity_type_manager;

			/// The entity attribute instance manager
			shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager;

			/// The entity attribute instance manager
			shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;

			/// The name of the new entity type.
			string entity_type_name;

			/// The UUID of the new entity type.
			string entity_type_uuid;

			/// The attribute definitions.
			unordered_map<string, ENTSYS_DATA_TYPE> entity_type_attributes;

	};


};
};
