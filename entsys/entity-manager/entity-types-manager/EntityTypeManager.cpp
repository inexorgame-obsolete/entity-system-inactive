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

    ENTSYS_RETURN_CODE EntityTypeManager::validate_new_entity_type(EntityType newtype)
    {
        //std::unordered_map<std::string,double>::const_iterator got = mymap.find (input);
        std::unordered_map<std::string,EntityType>::const_iterator validation = entity_types.find(newtype.name);
        if(validation == entity_types.end())
        {
            return ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID;
        }
        else
        {
            // a key/value pair for this entity does already exists!
            return ENTSYS_RETURN_ENTITY_TYPE_ALREADY_EXISTS;
        }
        return ENTSYS_RETURN_ERROR;
    }

    /// This method adds new types of entites.
    /// Entity type instances can only be created from existing valid entity types by the entity instance manager.
    ENTSYS_RETURN_CODE EntityTypeManager::create_entity_type(EntityType newtype)
    {
        // Before we can add a new entity type to the entity system it must be validated!
        if(ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID == validate_new_entity_type(newtype))
        {
            // add to unordered map
            entity_types[newtype.name] = newtype;
            return ENTSYS_RETURN_SUCCESS;
        }
        return ENTSYS_RETURN_ERROR;
    }

};
};
