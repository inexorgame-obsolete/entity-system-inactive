// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_MAIN_HEADER
#define INEXOR_ENTSYS_MAIN_HEADER

#include "EntitySystemErrorCodes.hpp"
#include "EntitySystemEntityType.hpp"
#include "EntityManager.hpp"

namespace inexor {
namespace entsys {

// Entity system singleton implementation
class CEntitySystem : public CEntityManager
{
    public:
        CEntitySystem();
        ~CEntitySystem();

};

};
};

#endif // INEXOR_ENTSYS_MAIN_HEADER
