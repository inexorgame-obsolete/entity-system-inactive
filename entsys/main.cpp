// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
using namespace std;

// entity system
#include "EntitySystem.hpp"
using namespace inexor;
using namespace entsys;

// Create singleton instance of the entity system.
EntitySystem* entity_system = EntitySystem::create_entity_system();

// TESTS
#include "tests/EntitySystemTests.hpp"

int main()
{
    // DATA CONTAINER TESTS
    Test_EntitySystemDataContainers();

    // ENTITY ATTRIBUTE TESTS
    Test_EntityAttributeTypes();

    // ENTITY TYPE TESTS
    Test_EntityTypes();

    cin.get();
    return 0;
}
