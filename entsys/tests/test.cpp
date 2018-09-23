// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#include <thread>
#include <mutex>
#include <memory>
#include <gtest/gtest.h>

// Tests for DataContainer class.
#include "test-components/DataContainerTests.hpp"

// Tests for types of entities and instances of them.
#include "test-components/EntityTypeTests.hpp"
//#include "test-components/EntityTypeManagerTests.hpp"
//#include "test-components/EntityTypeInstanceTests.hpp"
//#include "test-components/EntityTypeInstanceManagerTests.hpp"

// Tests for types of attributes of entities and instances of them.
#include "test-components/EntityAttributeTypeTests.hpp"
//#include "test-components/EntityAttributeTypeManagerTests.hpp"
//#include "test-components/EntityAttributeTypeInstanceTest.hpp"
//#include "test-components/EntityAttributeTypeInstanceManagerTests.hpp"

// TODO: Test for types of relations of entities and instances of them.

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
