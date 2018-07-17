// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER

#include <vector>
#include <string>
#include <unordered_map>
#include "../../return-codes/ReturnCodeEnum.hpp"
#include "entity-type\base\EntityTypeBase.hpp"

namespace inexor {
namespace entsys {

    /// \class EntityTypeManager
    /// \brief A manager class for types of entities.
    class EntityTypeManager 
    {
        private:
            std::unordered_map<std::string, EntityTypeBase> entity_types;

        protected:
            ENTSYS_RETURN_CODE validate_new_entity_type(const EntityTypeBase&) const;

        public:
            EntityTypeManager();
            ~EntityTypeManager();

            ENTSYS_RETURN_CODE create_entity_type(const EntityTypeBase&);
            const size_t get_entity_type_cound();
            // TODO: delete_entity_type() requires all instances of this entity type to be deleted as well!
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
