// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeManager.hpp"

namespace inexor {
namespace entsys {


    EntityAttributeTypeManager::EntityAttributeTypeManager()
    {
    }


    EntityAttributeTypeManager::~EntityAttributeTypeManager()
    {
    }


    const size_t EntityAttributeTypeManager::get_entity_attribute_type_count() const
    {
        return map_of_entity_attribute_types.size();
    }


    const ENTSYS_RETURN_CODE EntityAttributeTypeManager::does_entity_attribute_type_exist(std::string& entity_attribute_type_to_look_up) const
    {
        ENTSYS_ENTITY_ATTRIBUTE_TYPE_LOOKUP search_entity_attribute_type = map_of_entity_attribute_types.find(entity_attribute_type_to_look_up);
        if(search_entity_attribute_type == map_of_entity_attribute_types.end()) return ENTSYS_RETURN_ERROR_ENTITY_TYPE_UNAVAILABLE;
        return ENTSYS_RETURN_ERROR;
    }


    const ENTSYS_RETURN_CODE EntityAttributeTypeManager::add_entity_attribute_type(const EntityAttributeType& new_ent_attr_type)
    {
        // Add to map!
        // TODO: Prevent overwriting already existing entity attribute types!
        map_of_entity_attribute_types[new_ent_attr_type.get_name()] = new_ent_attr_type;
        return ENTSYS_RETURN_SUCCESS;
    }


};
};
