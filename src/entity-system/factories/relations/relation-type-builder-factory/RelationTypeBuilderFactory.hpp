#pragma once

#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/builders/relations/relation-type-builder/RelationTypeBuilder.hpp"

namespace inexor {
namespace entity_system {

	using RelationTypeBuilderPtr = std::shared_ptr<RelationTypeBuilder>;

	/// @class RelationTypeBuilder
	/// @brief Manages the builders for the relation type.
	class RelationTypeBuilderFactory
	{
		public:

			using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;
			using RelationAttributeTypeManagerPtr = std::shared_ptr<RelationAttributeTypeManager>;
			using RelationAttributeInstanceManagerPtr = std::shared_ptr<RelationAttributeInstanceManager>;

			/// Constructor.
			RelationTypeBuilderFactory(
			RelationTypeManagerPtr relation_type_manager,
			RelationAttributeTypeManagerPtr relation_attribute_type_manager,
			RelationAttributeInstanceManagerPtr relation_attribute_instance_manager
			);

			/// Destructor.
			~RelationTypeBuilderFactory();

			/// Initialization of the manager
			void init();

			/// Returns a new instance of a builder
			RelationTypeBuilderPtr get_builder();

		private:

			/// The relation type manager
			RelationTypeManagerPtr relation_type_manager;

			/// The relation attribute instance manager
			RelationAttributeTypeManagerPtr relation_attribute_type_manager;

			/// The relation attribute instance manager
			RelationAttributeInstanceManagerPtr relation_attribute_instance_manager;
	};


}
}
