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
    // Print minimum and maximum memory values.
    Print_MinimumMaximumMemoryValues();

    // Test by making false API calls:
    Test_DataContainer_CorrectUsage();

    // Test by making correct API calls:
    // Test_DataContainer_ErrorUsage();

    cin.get();
    return 0;
}
