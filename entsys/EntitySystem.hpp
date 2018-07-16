// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_CLASS_MAIN_HEADER
#define INEXOR_ENTSYS_CLASS_MAIN_HEADER

#include "entity-manager/EntityManager.hpp"

namespace inexor {
namespace entsys {

    /// \class CEntitySystem
    /// \brief Singleton implementation of an entity system prototype class for Inexor.
    class EntitySystem : public EntityManager // TODO ,public EntityEditor, public EntityRenderer
    {
        private:

            // singleton implementation:
            // private constructor to prevent double instancing
            EntitySystem();
            static EntitySystem* entsys_singleton_instance;

        public:

            ~EntitySystem();
            static EntitySystem* create_entity_system();

    };

};
};

#endif // INEXOR_ENTSYS_CLASS_MAIN_HEADER
