// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <iostream>
#include <mutex>

#include "entity-manager/EntityManager.hpp"


namespace inexor {
namespace entity_system {


    // TODO: Implement
	//			EntityEditor
	//			EntityEditorRenderer
	//			EntityGameSceneRenderer,
    //			EntitySync
	//			EntityErrorHandling
	//			EntityImporter
	//			EntityExporter


    // Entity system prototype for Inexor.
	// Currently this class is not a singleton implementation.
	class EntitySystem : public EntityManager
	{
		public:

			EntitySystem();
	};


};
};
