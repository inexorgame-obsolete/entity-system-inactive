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

	/// @class EntityTypeBuilderFactory
	/// @brief A builder class for entity types.
	/// @note For more information on the builder software pattern see
	/// https://en.wikipedia.org/wiki/Builder_pattern
	class EntityTypeBuilderFactory
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically with the help of Boost DI.<br>
			/// For more information see https://boost-experimental.github.io/di/user_guide/index.html
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// @param entity_type_manager A shared pointer to the entity type manager.
			/// @param entity_attribute_type_manager A shared pointer to the entity attribute type manager.
			/// @param entity_attribute_instance_manager A shared pointer to the entity attribute instance manager.
			EntityTypeBuilderFactory(
				EntityTypeManagerPtr entity_type_manager,
				EntityAttributeTypeManagerPtr entity_attribute_type_manager,
				EntityAttributeInstanceManagerPtr entity_attribute_instance_manager
			);

			/// @brief Destructor.
			~EntityTypeBuilderFactory();

			/// @brief Initialization of the manager.
			void init();

			/// @brief Returns a new instance of a builder.
			/// @return A std::shared pointer to the entity type builder.
			EntityTypeBuilderPtr get_builder();

		private:

			/// The entity type manager.
			EntityTypeManagerPtr entity_type_manager;

			/// The entity attribute instance manager.
			EntityAttributeTypeManagerPtr entity_attribute_type_manager;

			/// The entity attribute instance manager.
			EntityAttributeInstanceManagerPtr entity_attribute_instance_manager;

			/// The mutex of this class.
			std::mutex entity_type_builder_factory;

	};

}
}
