#pragma once

#include "../data-container/DataContainer.cpp"
using namespace inexor::entity_system;


TEST(DataContainerTest, DataTypeIntegerConstructor)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_INT);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}

TEST(DataContainerTest, DataTypeIntegerValueConstructor)
{
	int IntegerTestValue = 1994;
	DataContainer IntegerContainer(IntegerTestValue);
	EXPECT_EQ(IntegerContainer.get_int(), IntegerTestValue);
}
