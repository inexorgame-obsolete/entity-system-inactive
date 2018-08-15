// Inexor entity system prototype
// (c)2018 Inexor

#include "EntitySystem.hpp"
#include "tests/EntitySystemTests.hpp"

using namespace inexor;
using namespace entity_system;

// Thread-safe C++11 implementation of a singleton pattern for the entity system.
std::unique_ptr<EntitySystem> EntitySystem::instance;
std::once_flag EntitySystem::onceFlag;

// Create one instance of the entity system.
EntitySystem& entsys = EntitySystem::Instance();


int main(int argc, char* argv[])
{   
    Print_MinimumMaximumMemoryValues();

	Test_DataContainer_CorrectUsage();
	Test_CreateEntityType_CorrectUsage();

	Test_CreateEntityType_IncorrectUsage();

    std::cin.get();
    return 0;
}
