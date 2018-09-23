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
		public:

			EntitySystem();
	};


};
};
