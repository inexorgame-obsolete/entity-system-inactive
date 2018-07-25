// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeManager.hpp"


namespace inexor {
namespace entity_system {


    EntityAttributeTypeManager::EntityAttributeTypeManager()
    {
    }


    EntityAttributeTypeManager::~EntityAttributeTypeManager()
    {
    }


    unsigned int EntityAttributeTypeManager::count() const
    {
        return map_of_entity_attribute_types.size();
    }


    // TODO: Rename!
    ENTSYS_RETURN_CODE EntityAttributeTypeManager::search_entity_attribute_type(std::string& entity_attribute_type_to_look_up) const
    {
        ENTSYS_ENTITY_ATTRIBUTE_TYPE_LOOKUP search = map_of_entity_attribute_types.find(entity_attribute_type_to_look_up);
        if(search == map_of_entity_attribute_types.end()) return ENTSYS_RETURN_ERROR_ENTITY_TYPE_UNAVAILABLE;
        return ENTSYS_RETURN_ERROR;
    }


    ENTSYS_RETURN_CODE EntityAttributeTypeManager::create_entity_attribute_type(const EntityAttributeType& new_ent_attr_type)
    {
        // TODO: Prevent overwriting already existing entity attribute types!
        // TODO: Validate input!
        map_of_entity_attribute_types[new_ent_attr_type.get_name()] = new_ent_attr_type;
        return ENTSYS_RETURN_SUCCESS;
    }


};
};
