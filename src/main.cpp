// Inexor entity system prototype
// (c)2018 Inexor

#include "EntitySystem.hpp"
using namespace inexor::entity_system;


// ENTITY-SYSTEM EXAMPLES
#include "../examples/examples.hpp"


int main(int argc, char* argv[])
{
	// Run entity-system examples.
	run_entsys_examples();
	// TODO: Move tests from here into a separate gtest project.
	// TODO: Setup google testing framework with CMake.

	std::cin.get();
    return 0;
}
