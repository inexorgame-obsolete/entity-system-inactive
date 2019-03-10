#pragma once

#include "entity-system/managers/EntityManager.hpp"
#include "entity-system/managers/RelationManager.hpp"
#include "entity-system/managers/BuilderFactoryManager.hpp"

#include <iostream>

namespace inexor {
namespace entity_system {

	/// @class EntitySystem
    /// @brief Entity system main class.
	class EntitySystem
	{
		public:

			using EntityManagerPtr = std::shared_ptr<EntityManager>;
			using RelationManagerPtr = std::shared_ptr<RelationManager>;
			using BuilderFactoryManagerPtr = std::shared_ptr<BuilderFactoryManager>;

			/// Constructor.
			EntitySystem(
				EntityManagerPtr entity_manager,
				RelationManagerPtr relation_manager,
				BuilderFactoryManagerPtr builder_factory_manager
			);

			/// Destructor.
			~EntitySystem();

			/// Resets the entire entity system.
			void reset_entity_system();

		private:

			/// The entity manager
			EntityManagerPtr entity_manager;

			/// The entity manager
			RelationManagerPtr relation_manager;

			/// The builder factory manager
			BuilderFactoryManagerPtr builder_factory_manager;

	};


}
}
