// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER

#include <vector>
#include <string>
#include <unordered_map>

#include "../../validation/DataValidation.hpp"

#include "entity-type\EntityType.hpp"


namespace inexor {
namespace entsys {

    // Use type definitions to make further definitions shorter.
    typedef std::unordered_map<std::string, EntityType> ENTSYS_ENTITY_TYPE_MAP;
    typedef ENTSYS_ENTITY_TYPE_MAP::const_iterator ENTSYS_ENTITY_TYPE_LOOKUP;
    typedef ENTSYS_ENTITY_TYPE_MAP::value_type ENTSYS_ENTMAP_TYPE;


    // A manager class for types of entities.
    class EntityTypeManager : public DataValidation
    {
        private:

            // This is the core data container in which all 
            // existing entity types will be stored by name (std::string).
            //ENTSYS_ENTITY_TYPE_MAP map_of_entity_types;
            std::unordered_map<std::string, EntityType> map_of_entity_types;

        protected:

            // Validation method for new types of entities.
            ENTSYS_RETURN_CODE validate_new_entity_type(const EntityType&) const;

        public:

            EntityTypeManager();

            ~EntityTypeManager();

            ENTSYS_RETURN_CODE validate();


            // TODO: DISCUSS: Do all these methods really have to be of const type and const methods?

            // This method adds new types of entites.
            // Entity type instances can only be created from existing valid entity types by the entity instance manager.
            ENTSYS_RETURN_CODE create_entity_type(const EntityType&);

            // This method returns the number of existing entity types available in the entity system.
            unsigned int count_entity_types() const;
            
            // This method look up if an entity type of a certain name does already exist.
            bool search_entity_type(const std::string&) const;

            // This method returns the entity type class (call by reference) of an entity type class name.
            ENTSYS_RETURN_CODE get_entity_type(const std::string&, EntityType&) const;

            EntityType get_entity_type(const std::string&) const;

            // TODO: Debug!
            // TODO: Make this const?
            ENTSYS_RETURN_CODE link_attribute_type_to_entity_type(const EntityType&, const EntityAttributeType&);


            // TODO: delete_entity_type() requires all instances of this entity type to be deleted as well!
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
