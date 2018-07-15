// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_CLASS_MAIN_HEADER
#define INEXOR_ENTSYS_CLASS_MAIN_HEADER

#include "entity-manager/EntityManager.hpp"

namespace inexor {
namespace entsys {

    /// \class CEntitySystem
    /// \brief Singleton implementation of an entity system prototype class for Inexor.
    class CEntitySystem : public CEntityManager // TODO ,public CEntityEditor, public CEntityRenderer
    {
        private:

            // singleton implementation:
            // private constructor to prevent double instancing
            CEntitySystem();
            static CEntitySystem* entsys_singleton_instance;

        public:

            ~CEntitySystem();
            static CEntitySystem* create_instance();

    };

};
};

#endif // INEXOR_ENTSYS_CLASS_MAIN_HEADER
