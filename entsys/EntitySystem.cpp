#include "EntitySystem.hpp"

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
    CEntitySystem* CEntitySystem::instance()
    {
        // if no instance exists create one
        if(nullptr == entsys_singleton_instance)
            entsys_singleton_instance = new CEntitySystem();
        return entsys_singleton_instance;
    }


};
};
