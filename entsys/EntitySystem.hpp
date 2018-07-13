// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_MAIN_HEADER
#define INEXOR_ENTSYS_MAIN_HEADER

#include "errorhandling/EntitySystemErrorCodes.hpp"
#include "manager/EntityManager.hpp"

namespace inexor {
namespace entsys {

// Entity system singleton implementation
class CEntitySystem : public CEntityManager
{
    public:
        CEntitySystem();
        ~CEntitySystem();

        // TODO
        void load();
        void save();

};

};
};

#endif // INEXOR_ENTSYS_MAIN_HEADER
