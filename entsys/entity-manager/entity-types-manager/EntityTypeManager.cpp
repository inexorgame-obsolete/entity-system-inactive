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

    ENTSYS_RETURN_CODE EntityTypeManager::validate_new_entity_type(EntityTypeBase newtype)
    {
        // Look this entity type name up in the unordered map.
        std::string name = newtype.get_entity_type_name();
        std::unordered_map<std::string, EntityTypeBase>::const_iterator validation = entity_types.find(name);

        // If we reached the end of the unordered_map before it has been found it does not exist yet.
        if(validation == entity_types.end()) return ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID;
        else return ENTSYS_RETURN_ENTITY_TYPE_ALREADY_EXISTS;

        return ENTSYS_RETURN_ERROR;
    }

    /// This method adds new types of entites.
    /// Entity type instances can only be created from existing valid entity types by the entity instance manager.
    ENTSYS_RETURN_CODE EntityTypeManager::create_entity_type(EntityTypeBase newtype)
    {
        // Before we can add a new entity type to the entity system it must be validated!
        if(ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID == validate_new_entity_type(newtype))
        {
            std::string name = newtype.get_entity_type_name();
            // add to unordered map
            entity_types[name] = newtype;
            return ENTSYS_RETURN_SUCCESS;
        }
        return ENTSYS_RETURN_ERROR;
    }

};
};
