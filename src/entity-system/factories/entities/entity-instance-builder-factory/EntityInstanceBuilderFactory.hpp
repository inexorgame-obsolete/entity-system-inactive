#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/builders/entities/entity-instance-builder/EntityInstanceBuilder.hpp"

namespace inexor {
namespace entity_system {
	
	/// These using instructions help to shorten the following code.
	using EntityInstanceBuilderPtr = std::shared_ptr<EntityInstanceBuilder>;
	using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
	using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;

	/// @class EntityInstanceBuilderFactory
	/// @brief A builder class for entity instances.
	/// @note For more information on the builder software pattern see
	/// https://en.wikipedia.org/wiki/Builder_pattern
	class EntityInstanceBuilderFactory
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically with the help of Boost DI.<br>
			/// For more information see https://boost-experimental.github.io/di/user_guide/index.html
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// @param entity_instance_manager A shared pointer entity instance manager.
			/// @param entity_type_manager A shared pointer to the entity type manager.
			EntityInstanceBuilderFactory(
				EntityInstanceManagerPtr entity_instance_manager,
				EntityTypeManagerPtr entity_type_manager
			);

			/// @brief Destructor.
			~EntityInstanceBuilderFactory();

			/// @brief Initialization of the manager.
			void init();

			/// @brief Returns a new instance of a builder.
			/// @return A std::shared pointer to the entity instance builder.
			EntityInstanceBuilderPtr get_builder();

		private:

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The entity type manager.
			EntityTypeManagerPtr entity_type_manager;

			/// The mutex of this class.
			std::mutex entity_instance_builder_factory;
	};

}
}
