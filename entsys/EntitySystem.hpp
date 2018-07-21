// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_CLASS_MAIN_HEADER
#define INEXOR_ENTSYS_CLASS_MAIN_HEADER

#include "entity-manager/EntityManager.hpp"

namespace inexor {
namespace entsys {

    // TODO: EntityEditor, EntityEditorRenderer, EntityGameSceneRenderer,
    // EntitySync, EntityErrorHandling, EntityImporter, EntityExporter.

    /// \class EntitySystem
    /// \brief Singleton implementation of an entity system prototype class for Inexor
    class EntitySystem : public EntityManager
    {
        private:
            // singleton implementation: private constructor to prevent multiple instancing.
            EntitySystem();
            static EntitySystem* entsys_singleton_instance;

        public:
            ~EntitySystem();
            static EntitySystem* create_entity_system();

    };

    // Don't create the instance of the entity system in a header file like this.
    // It will cause a linker error because of multiple definitions!
};
};

#endif // INEXOR_ENTSYS_CLASS_MAIN_HEADER
