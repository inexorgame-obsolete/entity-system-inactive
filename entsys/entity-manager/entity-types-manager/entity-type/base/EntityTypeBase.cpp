// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeBase.hpp"

namespace inexor {
namespace entsys {
    
    EntityTypeBase::EntityTypeBase(std::string ent_type_name)
    {
        name = ent_type_name;
    }

    //EntityTypeBase::EntityTypeBase()
    //{
    //}
    
    EntityTypeBase::~EntityTypeBase()
    {
    }

    const std::string& EntityTypeBase::get_entity_type_name() const
    {
        return name;
    }

};
};
