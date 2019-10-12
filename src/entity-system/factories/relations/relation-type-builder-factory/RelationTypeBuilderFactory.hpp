#pragma once

#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/builders/relations/relation-type-builder/RelationTypeBuilder.hpp"

namespace inexor {
namespace entity_system {


	/// @class RelationTypeBuilderFactory
	/// @brief A builder class for relation types.
	/// @note For more information on the builder software pattern see
	/// https://en.wikipedia.org/wiki/Builder_pattern
	class RelationTypeBuilderFactory
	{
		public:
		
			/// These using instructions help to shorten the following code.
			using RelationTypeBuilderPtr = std::shared_ptr<RelationTypeBuilder>;
			using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;
			using RelationAttributeTypeManagerPtr = std::shared_ptr<RelationAttributeTypeManager>;
			using RelationAttributeInstanceManagerPtr = std::shared_ptr<RelationAttributeInstanceManager>;

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically with the help of Boost DI.<br>
			/// For more information see https://boost-experimental.github.io/di/user_guide/index.html
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// @param relation_type_manager A shared pointer to the relation type manager.
			/// @param relation_attribute_type_manager A shared pointer to the relation attribute type manager.
			/// @param relation_attribute_instance_manager A shared pointer to the relation attribute instance manager.
			RelationTypeBuilderFactory(
				RelationTypeManagerPtr relation_type_manager,
				RelationAttributeTypeManagerPtr relation_attribute_type_manager,
				RelationAttributeInstanceManagerPtr relation_attribute_instance_manager
			);

			/// @brief Destructor.
			~RelationTypeBuilderFactory();

			/// @brief Initialization of the manager
			void init();

			/// @brief Returns a new instance of a builder.
			/// @return A std::shared pointer to the relation type builder.
			RelationTypeBuilderPtr get_builder();

		private:

			/// The relation type manager.
			RelationTypeManagerPtr relation_type_manager;

			/// The relation attribute instance manager.
			RelationAttributeTypeManagerPtr relation_attribute_type_manager;

			/// The relation attribute instance manager.
			RelationAttributeInstanceManagerPtr relation_attribute_instance_manager;

			/// The mutex of this class.
			std::mutex relation_type_builder_factory;
	};

}
}
