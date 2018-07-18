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


    const ENTSYS_RETURN_CODE EntityTypeManager::validate_new_entity_type(const EntityTypeBase& newtype) const
    {
        // Look this entity type name up in the unordered map.
        // If we reached the end of the unordered_map before it has been found it does not exist yet.
        if(entity_types.find(newtype.get_entity_type_name()) == entity_types.end()) return ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID;
        else return ENTSYS_RETURN_ENTITY_TYPE_ALREADY_EXISTS;

        // TODO: additional validation here!

        // Something went wrong!
        return ENTSYS_RETURN_ERROR;
    }


    const ENTSYS_RETURN_CODE EntityTypeManager::create_entity_type(const EntityTypeBase& newtype)
    {
        // Before we can add a new entity type to the entity system it must be validated!
        ENTSYS_RETURN_CODE validation_result = validate_new_entity_type(newtype);

        // Add the new entity type in case it is valid.
        if(ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID == validation_result)
        {
            // add to unordered map
            entity_types.insert(ENTSYS_ENTMAP_TYPE(newtype.get_entity_type_name(), newtype));
            // TODO: Why is this not working?
            //entity_types[name] = newtype;
            return ENTSYS_RETURN_SUCCESS;
        }

        // something went wrong otherwise
        return validation_result;
    }


    const size_t EntityTypeManager::get_entity_type_cound() const
    {
        return entity_types.size();
    }


    const ENTSYS_RETURN_CODE EntityTypeManager::get_entity_type_class(std::string& entity_type_name, EntityTypeBase& entity_type_reference) const
    {
        // If we reached the end of the unordered_map before it has been found it does not exist yet.
        ENTSYS_ENTITY_TYPE_LOOKUP search_entity_type = entity_types.find(entity_type_name);
        if(search_entity_type == entity_types.end()) return ENTSYS_RETURN_ERROR_ENTITY_TYPE_UNAVAILABLE;

        // Fill out requested entity type (call by reference).
        entity_type_reference = search_entity_type->second;

        // Everything worked fine!
        return ENTSYS_RETURN_SUCCESS;
    }
    

    const bool EntityTypeManager::does_entity_type_exist(std::string& entity_type_to_look_up) const
    {
        // Check if a key/value pair for this entity type exists
        ENTSYS_ENTITY_TYPE_LOOKUP search_entity_type = entity_types.find(entity_type_to_look_up);
        return (search_entity_type == entity_types.end()) ? true : false;
    }


};
};
