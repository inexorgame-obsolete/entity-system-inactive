// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#include "gtest/gtest.h"

using namespace inexor::entity_system;

// Inexor entity system DataContainer class
#include "../../data-container/DataContainer.hpp"

TEST(DataContainerTest, ENTSYS_DATA_TYPE_INT)
{
	DataContainer IntContainer(ENTSYS_DATA_TYPE_INT);

}
