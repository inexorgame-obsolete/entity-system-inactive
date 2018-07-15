// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION
#define INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION

#include <vector>
#include <memory>

#include "../entity-base/EntSys_EntityBaseClass.hpp"

namespace inexor {
namespace entsys {

    // abstract class
    // no instance form this class can be made
    class CEntityRelationContext
    {
        private:

            // TODO: IMPORTANT: is this usage correct?
            std::vector<std::shared_ptr<CEntityBase>> from;
            std::vector<std::shared_ptr<CEntityBase>> to;

            // TODO: implement data structure 
            // for storing entity relation contexts            

        public:

            CEntityRelationContext();
            ~CEntityRelationContext();
    };

};
};


#endif // INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION
