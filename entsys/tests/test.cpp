// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#include <thread>
#include <mutex>
#include <memory>
#include <gtest/gtest.h>

// Tests for multi-purpose data container class.
#include "test-components/DataContainerTests.hpp"


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
