// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_MAIN_CLASS_HEADER
#define INEXOR_ENTSYS_MAIN_CLASS_HEADER

#include <iostream>
#include <mutex>

#include "../entsys/tests/EntitySystemDebugging.hpp"
#include "entity-manager/EntityManager.hpp"


namespace inexor {
namespace entity_system {


    // TODO: EntityEditor, EntityEditorRenderer, EntityGameSceneRenderer,
    // EntitySync, EntityErrorHandling, EntityImporter, EntityExporter.


    // Singleton implementation of an entity system prototype class for Inexor
	class EntitySystem : public EntityManager
	{
		private:

			// Delete all copy constructors because
      // a singleton can only be instanced once
      EntitySystem(const EntitySystem&) = delete;

      // Delete all copy constructors because
      // a singleton can only be instanced once
			EntitySystem & operator=(const EntitySystem&) = delete;

			//
			static std::unique_ptr<EntitySystem> instance;

			//
			static std::once_flag onceFlag;

		public:

			//
			EntitySystem() = default;

			//
			static EntitySystem& Instance();
	};


};
};

#endif // INEXOR_ENTSYS_CLASS_MAIN_HEADER
