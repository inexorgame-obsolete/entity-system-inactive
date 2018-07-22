// Inexor entity system prototype
// (c)2018 Inexor

#include "EntitySystem.hpp"

namespace inexor {
namespace entsys {


    EntitySystem::EntitySystem()
    {
    }


    EntitySystem::~EntitySystem()
    {
    }

    
    EntitySystem* EntitySystem::entsys_singleton_instance = nullptr;

    // Singleton implementation
    EntitySystem* EntitySystem::create_entity_system()
    {
        // Initialise instance if not already done.
        if(nullptr == entsys_singleton_instance)
        {
            // TODO: DISCUSS: Do we need to free this afterwards ?
            entsys_singleton_instance = new EntitySystem();
        }
        return entsys_singleton_instance;
    }


};
};
