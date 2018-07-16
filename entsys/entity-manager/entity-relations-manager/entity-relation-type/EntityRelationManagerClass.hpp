// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_RELATION_MANAGER_HEADER
#define INEXOR_ENTSYS_RELATION_MANAGER_HEADER

#include <vector>
#include "../../../return-codes/ReturnCodeEnum.hpp"
#include "../entity-relation-type/EntityRelationTypeBaseClass.hpp"

namespace inexor {
namespace entsys {

    /// \class CEntityRelationManager
    /// \brief The entiy relation manager is responsible for adding, modifying or removing relationships between entities.
    class EntityRelationManager
    {
        private:
            std::vector<EntityRelationTypeBase> relation;

        public:
            EntityRelationManager();
            ~EntityRelationManager();
        
            ENTSYS_RESULT_CODE add_relation();
            ENTSYS_RESULT_CODE modify_relation();
            ENTSYS_RESULT_CODE remove_relation();
    };

};
};

#endif // INEXOR_ENTSYS_RELATION_MANAGER_HEADER
