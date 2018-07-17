// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeBase.hpp"

namespace inexor {
namespace entsys {
    
    EntityTypeBase::EntityTypeBase(std::string ent_type_name)
    {
        entity_type_name = ent_type_name;
    }
    

    EntityTypeBase::EntityTypeBase()
    {
        entity_type_name = std::string("");
    }


    EntityTypeBase::~EntityTypeBase()
    {
    }


    const std::string& EntityTypeBase::get_entity_type_name() const
    {
        return entity_type_name;
    }

};
};
