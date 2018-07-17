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

    ENTSYS_RETURN_CODE EntityTypeManager::validate_new_entity_type(const EntityTypeBase& newtype) const
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
    ENTSYS_RETURN_CODE EntityTypeManager::create_entity_type(const EntityTypeBase& newtype)
    {
        // Before we can add a new entity type to the entity system it must be validated!
        ENTSYS_RETURN_CODE validation_result = validate_new_entity_type(newtype);

        // Add the new entity type in case it is valid.
        if(ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID == validation_result)
        {
            std::string name = newtype.get_entity_type_name();
            // add to unordered map
            entity_types.insert(std::unordered_map<std::string, EntityTypeBase>::value_type(name, newtype));
            //entity_types[name] = newtype;
            return ENTSYS_RETURN_SUCCESS;
        }

        // something went wrong otherwise
        return validation_result;
    }

    const size_t EntityTypeManager::get_entity_type_cound()
    {
        return entity_types.size();
    }

};
};
