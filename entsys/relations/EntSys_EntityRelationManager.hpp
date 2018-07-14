// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_RELATION_MANAGER_HEADER
#define INEXOR_ENTSYS_RELATION_MANAGER_HEADER

#include "../errorhandling/EntSys_ResultCodes.hpp"

namespace inexor {
namespace entsys {

    class CEntityRelationManager
    {
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
