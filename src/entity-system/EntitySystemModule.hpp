#pragma once

#include "entity-system/managers/EntityManager.hpp"
#include "entity-system/managers/RelationManager.hpp"
#include "entity-system/managers/BuilderFactoryManager.hpp"

namespace inexor {
namespace entity_system {

	/// The entity system module
	class EntitySystemModule
	{
		public:

			using EntityManagerPtr = std::shared_ptr<EntityManager>;
			using RelationManagerPtr = std::shared_ptr<RelationManager>;
			using BuilderFactoryManagerPtr = std::shared_ptr<BuilderFactoryManager>;

			/// Constructs the entity system module
			EntitySystemModule(
				EntityManagerPtr entity_manager,
				RelationManagerPtr relation_manager,
				BuilderFactoryManagerPtr builder_factory_manager
			);

			~EntitySystemModule();

			/// Resets the entire entity system.
			void reset_entity_system();

		private:

			/// The manager for entity types and entity instances
			EntityManagerPtr entity_manager;

			/// The manager for relation types and relation instances
			RelationManagerPtr relation_manager;

			/// The manager for the builder factories
			BuilderFactoryManagerPtr builder_factory_manager;

	};


}
}
