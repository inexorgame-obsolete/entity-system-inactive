// Inexor entity system prototype
// (c)2018 Inexor

#include "EntSys_EntityBaseClass.hpp"

namespace inexor {
namespace entsys {
    
    CEntityBase::CEntityBase(float x, float y, float z)
    {
        pos_x = x;
        pos_y = y;
        pos_z = z;
    }

    CEntityBase::~CEntityBase()
    {
    }

};
};
