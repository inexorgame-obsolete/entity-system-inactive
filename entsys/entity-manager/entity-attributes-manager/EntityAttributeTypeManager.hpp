// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER

#include "entity-attribute-type\EntityAttributeType.hpp"
#include "../entity-types-manager/entity-type/EntityType.hpp"
#include "../../return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entsys {
    

    class EntityAttributeTypeManager
    {
        private:

            // In this unordered map all available types of entity attributes will be stored.
            ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP map_of_entity_attribute_types;
            
            // TODO: Debug!
            ENTSYS_RETURN_CODE search_entity_attribute_type(std::string&) const;
            
        protected:

            // Make this protected so this class can only 
            // be instanced by inheritance as base class.
            EntityAttributeTypeManager();

            ~EntityAttributeTypeManager();

        public:

            // This method adds new types of attributes of entities.
            // Entity attribute type instances can only be created from existing valid 
            // entity attribute types by the entity attribute instance manager.
            ENTSYS_RETURN_CODE create_entity_attribute_type(const EntityAttributeType&);
                        
            // This method returns the number of existing types of entity attributes available in the entity system.
            unsigned int count() const;
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
