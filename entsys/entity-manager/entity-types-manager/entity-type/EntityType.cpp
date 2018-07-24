// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityType.hpp"


namespace inexor {
namespace entsys {
    

    EntityType::EntityType(const std::string& ent_type_name)
    {
        entity_type_name = ent_type_name;
    }
    

    EntityType::EntityType()
    {
    }
    

    EntityType::~EntityType()
    {
    }
    

    std::string EntityType::get_entity_type_name() const
    {
        // TODO: Change this definition?
        return std::string(entity_type_name);
    }


    ENTSYS_RETURN_CODE EntityType::set_entity_type_name(const std::string& name)
    {
        if(name.length() > 0)
        {
            entity_type_name = name;
            return ENTSYS_RETURN_SUCCESS;
        }
        return ENTSYS_RETURN_NAME_INVALID;
    }
    

    ENTSYS_RETURN_CODE EntityType::link_entity_attribute_type(const EntityAttributeType& ent_attr_type)
    {
        return ENTSYS_RETURN_SUCCESS;
    }

};
};
