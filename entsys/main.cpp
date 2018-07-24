// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
using namespace std;

#include "EntitySystem.hpp"
#include "tests/EntitySystemTests.hpp"
using namespace inexor;
using namespace entsys;

// Create singleton instance of the entity system.
EntitySystem* entity_system = EntitySystem::create_entity_system();


int main(int argc, char* argv[])
{
    // Add automatic tests here:
    Test_EntitySystemDataContainers();
    Test_EntityAttributeTypes();
    Test_EntityTypes();

    cin.get();
    return 0;
}
