// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "entity-system/builders/entities/entity-type-builder/EntityTypeBuilder.hpp"

using namespace std;

namespace inexor {
namespace entity_system {

	/// @class EntityTypeBuilder
    /// @brief Management of the loggers.
	class EntityTypeBuilderManager
	{
		public:

			/// Constructor.
			EntityTypeBuilderManager(
				shared_ptr<EntityTypeManager> entity_type_manager,
				shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager,
				shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
			);

			/// Destructor.
			~EntityTypeBuilderManager();

			/// Initialization of the manager
			void init();

			/// Returns a new instance of a builder
			shared_ptr<EntityTypeBuilder> get_builder();

		private:

			/// The entity type manager
			shared_ptr<EntityTypeManager> entity_type_manager;

			/// The entity attribute instance manager
			shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager;

			/// The entity attribute instance manager
			shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;
	};


};
};
