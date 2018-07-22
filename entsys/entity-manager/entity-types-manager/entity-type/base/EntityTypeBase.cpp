// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeBase.hpp"


namespace inexor {
namespace entsys {
    

    EntityTypeBase::EntityTypeBase(const std::string& ent_type_name)
    {
        entity_type_name = ent_type_name;
    }
    
    EntityTypeBase::EntityTypeBase()
    {
    }
    
    EntityTypeBase::~EntityTypeBase()
    {
    }
    
    const std::string& EntityTypeBase::get_name() const
    {
        return entity_type_name;
    }

    const ENTSYS_RETURN_CODE EntityTypeBase::set_name(const std::string& name)
    {
        if(name.length() > 0)
        {
            entity_type_name = name;
            return ENTSYS_RETURN_SUCCESS;
        }
        return ENTSYS_RETURN_NAME_INVALID;
    }
    
    const ENTSYS_RETURN_CODE EntityTypeBase::add(const EntityAttributeType& ent_attr_type)
    {
        entity_attribute_types[ent_attr_type.get_name()] = ent_attr_type;
        return ENTSYS_RETURN_SUCCESS;
    }

};
};
