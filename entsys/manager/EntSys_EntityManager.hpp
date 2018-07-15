// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_MANAGER_HEADER
#define INEXOR_ENTSYS_ENTITY_MANAGER_HEADER

#include <vector>

#include "../relations/EntSys_EntityRelationManager.hpp"
#include "../attributes/EntSys_EntityAttributeManager.hpp"
#include "../errorhandling/EntSys_ResultCodes.hpp"
#include "../entity-base/EntSys_EntityBase.hpp"

namespace inexor {
namespace entsys {

    // The entity manager class is responsible
    // for adding, modifying and removing entites.
    class CEntityManager : public CEntityAttributeManager,
                           public CEntityRelationManager
    {
        private:

            std::vector<CEntityBase> entities;
        
        public:

            CEntityManager();
            ~CEntityManager();

            ENTSYS_RESULT_CODE add_entity(CEntityBase);

            size_t entity_count();

            // TODO: how to access entites ?
            // by search parameters ? name ? UUID ?
            ENTSYS_RESULT_CODE remove_entity();

            void remove_all_entities();

    };

};
};


#endif // INEXOR_ENTSYS_ENTITY_MANAGER_HEADER
