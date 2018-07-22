// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER

#include <string>
#include "../../entity-types-manager/entity-type/base/EntityTypeBase.hpp"


namespace inexor {
namespace entsys {

    class EntityTypeInstance
    {
        private:

            EntityTypeBase type_of_entity;
             
        public:

            EntityTypeInstance();

            EntityTypeInstance(const std::string&);

            ~EntityTypeInstance();
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_CLASS_HEADER
