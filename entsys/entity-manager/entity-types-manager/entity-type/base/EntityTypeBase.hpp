// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER

#include <string>

namespace inexor {
namespace entsys {

    class EntityTypeBase {

        private:

            // entity data model
            // every entity has at least 
            // the following attributes (members)
            float x,y,z;

        public:

            EntityTypeBase(float,float,float);
            ~EntityTypeBase();

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER
