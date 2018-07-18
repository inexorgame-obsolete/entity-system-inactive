// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
using namespace std;

// entity system
#include "EntitySystem.hpp"
using namespace inexor;
using namespace entsys;

// TESTS
#include "tests/EntitySystemTests.hpp"

// create singleton instance
// a singleton class can only be instanced once!
// TODO: why does placing this in EntitySystem.hpp cause a linker error?
EntitySystem* sys = EntitySystem::create_entity_system();

int main()
{
    // DATA CONTAINER TESTS
    Test_EntitySystemDataContaners();

    // ENTITY TYPE TESTS

    // ENTITY ATTRIBUTE TESTS

    return 0;
}
