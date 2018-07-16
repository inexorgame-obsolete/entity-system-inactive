// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION
#define INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION

#include <vector>
#include <memory>

#include "../../entity-types-manager/entity-type/base/EntityTypeBase.hpp"

namespace inexor {
namespace entsys {

    // TODO: make this an abstract class
    class EntityRelationContext
    {
        private:

            // TODO: IMPORTANT: is this usage correct?
            std::vector<std::shared_ptr<EntityTypeBase>> from;
            std::vector<std::shared_ptr<EntityTypeBase>> to;

            // TODO: implement data structure 
            // for storing entity relation contexts            

        public:

            EntityRelationContext();
            ~EntityRelationContext();
    };

};
};


#endif // INEXOR_ENTSYS_ENTITY_RELATION_TYPE_BASE_CONNECTION
