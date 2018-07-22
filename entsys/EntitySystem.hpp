// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_MAIN_CLASS_HEADER
#define INEXOR_ENTSYS_MAIN_CLASS_HEADER

#include "../entsys/tests/EntitySystemDebugging.hpp"
#include "entity-manager/EntityManager.hpp"


namespace inexor {
namespace entsys {

    // TODO: EntityEditor, EntityEditorRenderer, EntityGameSceneRenderer,
    // EntitySync, EntityErrorHandling, EntityImporter, EntityExporter.

    // Singleton implementation of an entity system prototype class for Inexor
    class EntitySystem : public EntityManager
    {
        private:

            EntitySystem();

            // The singleton implementation of the entity system.
            static EntitySystem* entsys_singleton_instance;

        public:

            ~EntitySystem();

            // Create an instance of the entity system.
            static EntitySystem* create_entity_system();

    };
    

    // Don't create the instance of the entity system in a header file.
    // It could cause a linker error because of multiple definitions!

};
};

#endif // INEXOR_ENTSYS_CLASS_MAIN_HEADER
