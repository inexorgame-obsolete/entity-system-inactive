// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER

#include <vector>
#include <string>
#include <unordered_map>
#include "../../return-codes/ReturnCodeEnum.hpp"

namespace inexor {
namespace entsys {

    /// \brief Structure for describing entity types.
    struct EntityType
    {
        std::string name;
        // TODO: add UUID here!
        // Which entity attributes or relations should be build in here?
    };

    /// \class EntityTypeManager
    /// \brief A manager class for types of entities.
    class EntityTypeManager 
    {
        private:
            // TODO: discuss this
            std::unordered_map<std::string, EntityType> entity_types;
            ENTSYS_RETURN_CODE validate_new_entity_type(EntityType);

        public:
            EntityTypeManager();
            ~EntityTypeManager();

            ENTSYS_RETURN_CODE create_entity_type(EntityType);
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
