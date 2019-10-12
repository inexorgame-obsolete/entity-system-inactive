#pragma once

#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/builders/relations/relation-instance-builder/RelationInstanceBuilder.hpp"

namespace inexor {
namespace entity_system {


	/// @class RelationInstanceBuilderFactory
	/// @brief A builder class for relation instances.
	/// @note For more information on the builder software pattern see
	/// https://en.wikipedia.org/wiki/Builder_pattern
	class RelationInstanceBuilderFactory
	{
		public:

			/// These using instructions help to shorten the following code.
			using RelationInstanceBuilderPtr = std::shared_ptr<RelationInstanceBuilder>;
			using RelationInstanceManagerPtr = std::shared_ptr<RelationInstanceManager>;
			using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically with the help of Boost DI.<br>
			/// For more information see https://boost-experimental.github.io/di/user_guide/index.html
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// @param relation_instance_manager A shared pointer to the instance manager.
			/// @param relation_type_manager A shared pointer to the type manager.
			RelationInstanceBuilderFactory(
				RelationInstanceManagerPtr relation_instance_manager,
				RelationTypeManagerPtr relation_type_manager
			);

			/// @brief Destructor.
			~RelationInstanceBuilderFactory();

			/// @brief Initialization of the manager.
			void init();

			/// @brief Returns a new instance of a builder.
			/// @return A std::shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr get_builder();

		private:

			/// The relation instance manager.
			RelationInstanceManagerPtr relation_instance_manager;

			/// The relation type manager.
			RelationTypeManagerPtr relation_type_manager;

			/// The mutex of this class.
			std::mutex relation_instance_builder_factory_mutex;

	};

}
}
