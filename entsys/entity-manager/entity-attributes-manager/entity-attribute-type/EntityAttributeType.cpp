// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeType.hpp"

namespace inexor {
namespace entsys {

    EntityAttributeType::EntityAttributeType()
    {
    }


    EntityAttributeType::~EntityAttributeType()
    {
    }


    const ENTSYS_RETURN_CODE EntityAttributeType::set_name(const std::string& name)
    {
        if(name.length() > 0)
        {
            entity_attribute_type_name = name;
            return ENTSYS_RETURN_SUCCESS;
        }
        return ENTSYS_RETURN_ERROR;
    }


    const ENTSYS_RETURN_CODE EntityAttributeType::set_data_type(const ENTSYS_DATA_TYPE& type)
    {
        // Overwrite the data container's type of this entity attribute type
        // only of it's type has not been overwritten (specified) yet and only accept valid data types.
        if(ENTSYS_DATA_TYPE_UNSPECIFIED != type && !finished)
        {
            entity_attribute_data.set_data_type(type);
            return ENTSYS_RETURN_SUCCESS;
        }
        return ENTSYS_RETURN_ERROR;
    }
    
    
    const ENTSYS_RETURN_CODE EntityAttributeType::finish_entity_attribute_type()
    {
        if(entity_attribute_data.get_data_type() != ENTSYS_DATA_TYPE_UNSPECIFIED && entity_attribute_type_name.length() > 0)
        {
            finished = true;
            return ENTSYS_RETURN_SUCCESS;
        }
        return ENTSYS_RETURN_ERROR;
    }


    const ENTSYS_DATA_TYPE EntityAttributeType::get_data_type() const
    {
        return entity_attribute_data.get_data_type();
    }

    
    const std::string EntityAttributeType::get_name() const
    {
        return entity_attribute_type_name;
    }


    const bool EntityAttributeType::is_finished() const
    {
        return finished;
    }

};
};
