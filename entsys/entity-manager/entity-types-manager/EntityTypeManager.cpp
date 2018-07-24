// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeManager.hpp"


namespace inexor {
namespace entsys {
    

    EntityTypeManager::EntityTypeManager()
    {
    }


    EntityTypeManager::~EntityTypeManager()
    {
    }


    ENTSYS_RETURN_CODE EntityTypeManager::validate()
    {
        // TODO: Implement!
        return ENTSYS_RETURN_SUCCESS;
    }


    ENTSYS_RETURN_CODE EntityTypeManager::validate_new_entity_type(const EntityType& newtype) const
    {
        // Look this entity type name up in the unordered map.
        // If we reached the end of the unordered_map before it has been found it does not exist yet.
        // TODO: Change this so it uses the does_entity_type_exist() method.
        if(map_of_entity_types.find(newtype.get_entity_type_name()) == map_of_entity_types.end()) return ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID;
        else return ENTSYS_RETURN_ENTITY_TYPE_ALREADY_EXISTS;

        // TODO: Additional validation here!

        return ENTSYS_RETURN_ERROR;
    }


    ENTSYS_RETURN_CODE EntityTypeManager::create_entity_type(const EntityType& newtype)
    {
        // Before we can add a new entity type to the entity system it must be validated!
        ENTSYS_RETURN_CODE validation_result = validate_new_entity_type(newtype);

        // Add the new entity type in case it is valid.
        if(ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID == validation_result)
        {
            // add to unordered map
            map_of_entity_types[newtype.get_entity_type_name()] = newtype;
            return ENTSYS_RETURN_SUCCESS;
        }

        // something went wrong otherwise
        return validation_result;
    }


    unsigned int EntityTypeManager::count_entity_types() const
    {
        return map_of_entity_types.size();
    }


    ENTSYS_RETURN_CODE EntityTypeManager::get_entity_type(const std::string& entity_type_name, EntityType& entity_type_reference) const
    {
        // If we reached the end of the unordered_map before it has been found it does not exist yet.
        ENTSYS_ENTITY_TYPE_LOOKUP search = map_of_entity_types.find(entity_type_name);
        if(search == map_of_entity_types.end()) return ENTSYS_RETURN_ERROR_ENTITY_TYPE_UNAVAILABLE;

        // Fill out requested entity type (call by reference).
        entity_type_reference = search->second;

        // Everything worked fine!
        return ENTSYS_RETURN_SUCCESS;
    }
    

    EntityType EntityTypeManager::get_entity_type(const std::string& entity_type_name) const
    {
        // If we reached the end of the unordered_map before it has been found it does not exist yet.
        ENTSYS_ENTITY_TYPE_LOOKUP search = map_of_entity_types.find(entity_type_name);
        if(search == map_of_entity_types.end()) return EntityType("invalid");

        return search->second;
    }

    
    bool EntityTypeManager::search_entity_type(const std::string& entity_type_to_look_up) const
    {
        // Check if a key/value pair for this entity type exists
        ENTSYS_ENTITY_TYPE_LOOKUP search_entity_type = map_of_entity_types.find(entity_type_to_look_up);
        return (search_entity_type == map_of_entity_types.end()) ? true : false;
    }

    
    ENTSYS_RETURN_CODE EntityTypeManager::link_attribute_type_to_entity_type(const EntityType& ent_type, const EntityAttributeType& ent_attr_type)
    {
        // TODO: Debug!
        map_of_entity_types[ent_type.get_entity_type_name()].link_entity_attribute_type(ent_attr_type);

        // TODO: Resolve!
        return ENTSYS_RETURN_ERROR;
    }

};
};
