// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeBase.hpp"

namespace inexor {
namespace entsys {
    
    EntityTypeBase::EntityTypeBase(float pos_x, float pos_y, float pos_z)
    {
        x = pos_x;
        y = pos_y;
        z = pos_z;
    }

    EntityTypeBase::~EntityTypeBase()
    {
    }

};
};
