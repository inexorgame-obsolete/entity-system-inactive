// Inexor entity system prototype
// (c)2018 Inexor

#include "EntSysClass.hpp"

namespace inexor {
namespace entsys {

    CEntitySystem::CEntitySystem()
    {
    }

    CEntitySystem::~CEntitySystem()
    {
    }

    CEntitySystem* CEntitySystem::entsys_singleton_instance = 0;

    // singleton implementation
    CEntitySystem* CEntitySystem::create_instance()
    {
        // if no instance exists create one
        if(nullptr == entsys_singleton_instance)
            entsys_singleton_instance = new CEntitySystem();
        return entsys_singleton_instance;
    }


};
};
