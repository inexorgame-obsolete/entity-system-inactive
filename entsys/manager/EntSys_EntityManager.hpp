// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_MANAGER
#define INEXOR_ENTSYS_ENTITY_MANAGER

#include "../relations/EntSys_EntityRelationManager.hpp"
#include "../attributes/EntSys_EntityAttributeManager.hpp"
#include "../errorhandling/EntSys_ResultCodes.hpp"

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

        INEXOR_ENTSYS_RESULT_CODE add_ent();
        INEXOR_ENTSYS_RESULT_CODE modify_ent();
        INEXOR_ENTSYS_RESULT_CODE remove_ent();
};

};
};


#endif // INEXOR_ENTSYS_ENTITY_MANAGER
