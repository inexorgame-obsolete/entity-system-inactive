// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
using namespace std;

#include "EntitySystem.hpp"
#include "tests/EntitySystemTests.hpp"
using namespace inexor;
using namespace entity_system;

// Create singleton instance of the entity system.
EntitySystem* entsys = EntitySystem::create_entity_system();


int main(int argc, char* argv[])
{   
    // Windows specific only
    #ifdef WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 13); // purple
    #endif

    // Test by making false API calls.
    ErrorTest_DataContainer();

    // Test by making correct API calls.
    Test_EntityTypes();
    Test_EntityAttributeTypes();
    Test_EntitySystemDataContainers();
    TestEntityTypes_and_EntityTypeAttributes();

    cin.get();
    return 0;
}
