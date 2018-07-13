// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_MANAGER
#define INEXOR_ENTSYS_ENTITY_MANAGER

#include "../relations/EntityRelationManager.hpp"
#include "../attributes/EntityAttributeManager.hpp"

namespace inexor {
namespace entsys {

// The entity manager class is responsible
// for adding, modifying and removing entites.
class CEntityManager : public CEntityAttributeManager,
                       public CEntityRelationManager
{
    protected:
        void add_entity();
        void remove_entity();
        void remove_all_entities();

    public:
        CEntityManager();
        ~CEntityManager();

};

};
};


#endif // INEXOR_ENTSYS_ENTITY_MANAGER
