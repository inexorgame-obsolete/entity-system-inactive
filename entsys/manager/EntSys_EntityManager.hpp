// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_MANAGER_HEADER
#define INEXOR_ENTSYS_ENTITY_MANAGER_HEADER

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
        ENTSYS_RESULT_CODE add_entity();
        ENTSYS_RESULT_CODE remove_entity();
        ENTSYS_RESULT_CODE remove_all_entities();

    public:
        CEntityManager();
        ~CEntityManager();

};

};
};


#endif // INEXOR_ENTSYS_ENTITY_MANAGER_HEADER
