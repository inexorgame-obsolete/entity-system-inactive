#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"

#include "entity-system/builders/entities/entity-instance-builder/EntityInstanceBuilder.hpp"

namespace inexor {
namespace entity_system {

	using EntityInstanceBuilderPtr = std::shared_ptr<EntityInstanceBuilder>;

	/// @class EntityTypeBuilder
    /// @brief Management of the loggers.
	class EntityInstanceBuilderFactory
	{
		public:

			using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
			using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;

			/// Constructor.
			EntityInstanceBuilderFactory(
				EntityInstanceManagerPtr entity_instance_manager,
				EntityTypeManagerPtr entity_type_manager
			);

			/// Destructor.
			~EntityInstanceBuilderFactory();

			/// Initialization of the manager
			void init();

			/// Returns a new instance of a builder
			EntityInstanceBuilderPtr get_builder();

		private:

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The entity type manager
			EntityTypeManagerPtr entity_type_manager;

	};


};
};
