// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#include <thread>
#include <mutex>
#include <memory>
#include <gtest/gtest.h>

#include "../EntitySystem.hpp"

#include "test-components/DataContainerTests.hpp"
#include "test-components/EntityTypeManagerTests.hpp"
#include "test-components/EntityTypeTests.hpp"
#include "test-components/EntityAttributeTypeTests.hpp"


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
