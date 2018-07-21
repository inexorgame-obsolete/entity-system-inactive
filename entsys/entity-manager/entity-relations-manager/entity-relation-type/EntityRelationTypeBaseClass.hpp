// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_RELATION_TYPE_BASE_CLASS_HEADER
#define INEXOR_ENTSYS_RELATION_TYPE_BASE_CLASS_HEADER

#include <vector>
#include <string>
#include "EntityRelationTypeContextClass.hpp"

namespace inexor {
namespace entsys {

    // This is the base class for the description of relations between entities.
    class EntityRelationTypeBase
    {
        private:
            std::vector<EntityRelationContext> entity_relation;
            // TODO: data container here

        public:
            EntityRelationTypeBase();        
            ~EntityRelationTypeBase();        
    };

};
};

#endif // INEXOR_ENTSYS_RELATION_TYPE_BASE_CLASS_HEADER
