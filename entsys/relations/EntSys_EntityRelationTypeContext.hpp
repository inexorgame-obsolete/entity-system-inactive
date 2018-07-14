// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION
#define INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION

#include <vector>

#include "../entity-base/EntSys_EntityBase.hpp"

namespace inexor {
namespace entsys {

    // abstract class
    // no instance form this class can be made
    class CEntityRelationContext
    {
        private:

            std::vector<CEntityBase*> from;
            std::vector<CEntityBase*> to;

            // TODO: implement data structure 
            // for storing entity relation contexts            

        public:

            CEntityRelationContext();
            ~CEntityRelationContext();
    };

};
};


#endif // INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION
