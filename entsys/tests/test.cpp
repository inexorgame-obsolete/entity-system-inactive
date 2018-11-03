// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#include <thread>
#include <mutex>
#include <memory>
#include <gtest/gtest.h>

// Tests for DataContainer class.
#include "test-components/data-container-tests/DataContainerTests.hpp"

// Tests for types of entities and instances of them.
//#include "test-components/type-tests/entity-type-tests/EntityTypeTests.hpp"

// Tests for types of attributes of entities and instances of them.

// Tests for types of relations of entities and instances of them.


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
