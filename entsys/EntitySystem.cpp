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


    EntitySystem* EntitySystem::entsys_singleton_instance = 0;


    // singleton implementation
    EntitySystem* EntitySystem::create_entity_system()
    {
        // if no instance exists create one
        if(nullptr == entsys_singleton_instance)
            entsys_singleton_instance = new EntitySystem();
        return entsys_singleton_instance;
    }

};
};
