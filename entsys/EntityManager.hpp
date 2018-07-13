// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_MANAGER
#define INEXOR_ENTSYS_ENTITY_MANAGER

#include "EntityRelationManager.hpp"
#include "EntityAttributeManager.hpp"

namespace inexor {
namespace entsys {

class CEntityManager : public CEntityAttributeManager,
                       public CEntityRelationManager
{
    public:
       CEntityManager();
       ~CEntityManager();

       void add_entity();
       void remove_entity();
};

};
};


#endif // INEXOR_ENTSYS_ENTITY_MANAGER
