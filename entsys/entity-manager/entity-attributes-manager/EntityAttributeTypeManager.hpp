// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER

#include <string>
#include <unordered_map>
#include "entity-attribute-type\EntityAttributeType.hpp"
#include "../../return-codes/ReturnCodes.hpp"

namespace inexor {
namespace entsys {
    
    /// Let's use these type definitions to shorten declarations.
    typedef std::unordered_map<std::string, EntityAttributeType> ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP;
    typedef ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP::const_iterator     ENTSYS_ENTITY_ATTRIBUTE_TYPE_LOOKUP;

    /// 
    class EntityAttributeTypeManager
    {
        private:
            // In this unordered map all available types of entity attributes will be stored.
            ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP map_of_entity_attribute_types;

            // Validation method for new entity attribute types.
            const bool validate_new_entity_attribute_type(const EntityAttributeType&) const;

            // TODO: Debug!
            const ENTSYS_RETURN_CODE does_entity_attribute_type_exist(std::string&) const;
            
        protected:
            // Make this protected so this class can only 
            // be instanced as an inherited base class.
            EntityAttributeTypeManager();

        public:
            ~EntityAttributeTypeManager();

            // This method adds new types of attributes of entities.
            // Entity attribute type instances can only be created from existing valid 
            // entity attribute types by the entity attribute instance manager.
            const ENTSYS_RETURN_CODE add_entity_attribute_type(const EntityAttributeType&);

            // This method returns the number of existing types of entity attributes available in the entity system.
            const size_t get_entity_attribute_type_count() const;
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
