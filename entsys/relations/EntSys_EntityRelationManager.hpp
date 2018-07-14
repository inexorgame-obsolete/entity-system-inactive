// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_RELATION_MANAGER_HEADER
#define INEXOR_ENTSYS_RELATION_MANAGER_HEADER

#include <vector>

#include "../errorhandling/EntSys_ResultCodes.hpp"
#include "../relations/EntSys_EntityRelationTypeBase.hpp"

namespace inexor {
namespace entsys {

    class CEntityRelationManager
    {
        private:

            // TODO: rewrite. This base class is not inherited
            std::vector<CEntityRelationTypeBase> relation;

        public:

            CEntityRelationManager();
            ~CEntityRelationManager();
        
            ENTSYS_RESULT_CODE add_relation();
            ENTSYS_RESULT_CODE modify_relation();
            ENTSYS_RESULT_CODE remove_relation();
    };

};
};

#endif // INEXOR_ENTSYS_RELATION_MANAGER_HEADER
