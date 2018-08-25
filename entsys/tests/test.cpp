// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#include <thread>
#include <mutex>
#include <memory>
#include <gtest/gtest.h>

#include "../EntitySystem.hpp"
#include "test-components/DataContainerTests.hpp"


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
