// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
using namespace std;

// entity system
#include "entsys\EntSys.hpp"
using namespace inexor;

// create singleton instance
// a singleton class can only be instanced once!
entsys::CEntitySystem* sys = nullptr;

int main()
{
    // initialize singleton instance
    sys = entsys::CEntitySystem::create_instance();
    entsys::CEntityBase new_entity(0.0f, 0.0f, 0.0f);    
    sys->add_entity(new_entity);
    return 0;
}
