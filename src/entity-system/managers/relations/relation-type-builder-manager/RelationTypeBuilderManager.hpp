// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "entity-system/builders/relations/relation-type-builder/RelationTypeBuilder.hpp"

using namespace std;

namespace inexor {
namespace entity_system {

	/// @class RelationTypeBuilder
    /// @brief Manages the builders for the relation type.
	class RelationTypeBuilderManager
	{
		public:

			/// Constructor.
			RelationTypeBuilderManager(
				shared_ptr<RelationTypeManager> entity_type_manager,
				shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager,
				shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
			);

			/// Destructor.
			~RelationTypeBuilderManager();

			/// Initialization of the manager
			void init();

			/// Returns a new instance of a builder
			shared_ptr<RelationTypeBuilder> get_builder();

		private:

			/// The relation type manager
			shared_ptr<RelationTypeManager> relation_type_manager;

			/// The relation attribute instance manager
			shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager;

			/// The relation attribute instance manager
			shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager;
	};


};
};
