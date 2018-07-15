// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_NODE_BASE_CLASS
#define INEXOR_ENTSYS_ENTITY_NODE_BASE_CLASS

#include <string>

namespace inexor {
namespace entsys {

    class CEntityBase {

        private:

            // entity data model
            // every entity has at least 
            // the following attributes (members)
            float pos_x;
            float pos_y;
            float pos_z;

        public:

            CEntityBase(float,float,float);
            ~CEntityBase();

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_NODE_BASE_CLASS
