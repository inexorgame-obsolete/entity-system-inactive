#pragma once

#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/builders/entities/entity-type-builder/EntityTypeBuilder.hpp"

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using EntityTypeBuilderPtr = std::shared_ptr<EntityTypeBuilder>;
	using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;
	using EntityAttributeTypeManagerPtr = std::shared_ptr<EntityAttributeTypeManager>;
	using EntityAttributeInstanceManagerPtr = std::shared_ptr<EntityAttributeInstanceManager>;


	/// @class EntityTypeBuilder
	/// @brief Management of the loggers.
	class EntityTypeBuilderFactory
	{
		public:

			/// Constructor.
			EntityTypeBuilderFactory(
				EntityTypeManagerPtr entity_type_manager,
				EntityAttributeTypeManagerPtr entity_attribute_type_manager,
				EntityAttributeInstanceManagerPtr entity_attribute_instance_manager
			);

			/// Destructor.
			~EntityTypeBuilderFactory();

			/// Initialization of the manager
			void init();

			/// Returns a new instance of a builder
			EntityTypeBuilderPtr get_builder();

		private:

			/// The entity type manager
			EntityTypeManagerPtr entity_type_manager;

			/// The entity attribute instance manager
			EntityAttributeTypeManagerPtr entity_attribute_type_manager;

			/// The entity attribute instance manager
			EntityAttributeInstanceManagerPtr entity_attribute_instance_manager;

			/// The mutex of this class.
			std::mutex entity_type_builder_factory;

	};

}
}
