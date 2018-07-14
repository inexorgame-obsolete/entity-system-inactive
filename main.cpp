// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
using namespace std;

// entity system
#include "entsys\EntitySystem.hpp"

inexor::entsys::CEntitySystem* sys = nullptr;

int main()
{
    sys = inexor::entsys::CEntitySystem::instance();
    return 0;
}
