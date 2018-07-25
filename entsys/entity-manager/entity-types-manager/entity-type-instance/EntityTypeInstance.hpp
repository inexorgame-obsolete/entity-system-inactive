// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER

#include <string>
#include "../../entity-types-manager/entity-type/EntityType.hpp"


namespace inexor {
namespace entity_system {

    class EntityTypeInstance : public EntityType
    {
        public:

            EntityTypeInstance();

            EntityTypeInstance(const std::string&);

            ~EntityTypeInstance();

            // TODO: Only instances should be abled to write to attributes ?
            
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER
