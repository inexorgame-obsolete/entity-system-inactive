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


    size_t EntityAttributeTypeManager::count() const
    {
        return map_of_entity_attribute_types.size();
    }


    ENTSYS_RETURN_CODE EntityAttributeTypeManager::search_entity_attribute_type(std::string& entity_attribute_type_to_look_up) const
    {
        ENTSYS_ENTITY_ATTRIBUTE_TYPE_LOOKUP search = map_of_entity_attribute_types.find(entity_attribute_type_to_look_up);
        if(search == map_of_entity_attribute_types.end()) return ENTSYS_RETURN_ERROR_ENTITY_TYPE_UNAVAILABLE;
        return ENTSYS_RETURN_ERROR;
    }


    ENTSYS_RETURN_CODE EntityAttributeTypeManager::create_entity_attribute_type(const EntityAttributeType& new_ent_attr_type)
    {
        // Add to map!
        // TODO: Prevent overwriting already existing entity attribute types!
        map_of_entity_attribute_types[new_ent_attr_type.get_name()] = new_ent_attr_type;
        return ENTSYS_RETURN_SUCCESS;
    }


    ENTSYS_RETURN_CODE EntityAttributeTypeManager::link_attribute_type_to_entity_type(const EntityType& ent_type, const EntityAttributeType& ent_attr_type) const
    {
        //map_of_entity_attribute_types[ent_type.get_entity_type_name()] = ent_attr_type;
        // TODO: Resolve!
        return ENTSYS_RETURN_ERROR;
    }


};
};
