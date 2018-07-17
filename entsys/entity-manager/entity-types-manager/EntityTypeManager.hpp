// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER

#include <vector>
#include <string>
#include <unordered_map>
#include "../../return-codes/ReturnCodes.hpp"
#include "entity-type\base\EntityTypeBase.hpp"

namespace inexor {
namespace entsys {

    /// Let's use a type definition to shorten this iterator.
    typedef std::unordered_map<std::string, EntityTypeBase>::const_iterator ENTSYS_ENTITY_TYPE_LOOKUP;
    
    /// Let's use a type definition to shorten this value type.
    typedef std::unordered_map<std::string, EntityTypeBase>::value_type ENTSYS_ENTMAP_TYPE;

    /// \class EntityTypeManager
    /// \brief A manager class for types of entities.
    class EntityTypeManager 
    {
        private:

            /// This is the core data container in which all existing entity types will be stored by name (std::string).
            std::unordered_map<std::string, EntityTypeBase> entity_types;

        protected:

            /// This method validates new entity types which want to be taken into the system.
            const ENTSYS_RETURN_CODE validate_new_entity_type(const EntityTypeBase&) const;
            
        public:

            EntityTypeManager();
            ~EntityTypeManager();

            // TODO: Do all these methods really have to be of const type and const methods?

            /// This method adds new types of entites.
            /// Entity type instances can only be created from existing valid entity types by the entity instance manager.
            const ENTSYS_RETURN_CODE create_entity_type(const EntityTypeBase&);

            /// This method returns the number of existing entity types available in the entity system.
            const size_t get_entity_type_cound() const;
            
            /// This method look up if an entity type of a certain name does already exist.
            const bool does_entity_type_exist(std::string&) const;

            /// This method returns the entity type class (call by reference) of an entity type class name.
            const ENTSYS_RETURN_CODE get_entity_type_class(std::string&, EntityTypeBase&) const;

            // TODO: delete_entity_type() requires all instances of this entity type to be deleted as well!
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
