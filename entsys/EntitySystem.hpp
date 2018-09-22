// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <iostream>
#include <mutex>

#include "entity-manager/EntityManager.hpp"


namespace inexor {
namespace entity_system {


    // TODO: EntityEditor, EntityEditorRenderer, EntityGameSceneRenderer,
    // EntitySync, EntityErrorHandling, EntityImporter, EntityExporter.

    // Singleton implementation of an entity system prototype class for Inexor.
	class EntitySystem : public EntityManager
	{
		private:

			// Delete all copy constructors because
			// a singleton can only be instanced once.
			EntitySystem(const EntitySystem&) = delete;

			// Delete all copy constructors because
			// a singleton can only be instanced once.
			EntitySystem & operator=(const EntitySystem&) = delete;

			static std::unique_ptr<EntitySystem> instance;

			static std::once_flag onceFlag;

		public:

			EntitySystem() = default;

			static EntitySystem& Instance();
	};


	// Thread-safe C++11 implementation of
	// a singleton class pattern for the entity system.
	std::unique_ptr<EntitySystem> EntitySystem::instance;
	std::once_flag EntitySystem::onceFlag;

	// Create one instance of the entity system.
	EntitySystem& entsys = EntitySystem::Instance();


};
};
