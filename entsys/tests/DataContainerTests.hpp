#pragma once

#include "../../data-container/DataContainer.cpp"
using namespace inexor::entity_system;


// A testing class for DataContainer.
class DataContainerTest : public ::testing::Test
{
	protected:

		// You can remove any or all of the following functions if its body
		// is empty.

		DataContainerTest()
		{
			// You can do set-up work for each test here.
		}

		~DataContainerTest() override
		{
			// You can do clean-up work that doesn't throw exceptions here.
		}

		// If the constructor and destructor are not enough for setting up
		// and cleaning up each test, you can define the following methods:

		void SetUp() override
		{
			// Code here will be called immediately after the constructor (right
			// before each test).
		}

		void TearDown() override
		{
			// Code here will be called immediately after each test (right
			// before the destructor).
		}
		
};


// TODO: Not sure if we need this yet.
TEST_F(DataContainerTest, ExampleTestCase1)
{
	//DataContainer IntegerContainer(ENTSYS_DATA_TYPE_INT);
	//EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}


TEST(DataContainerTest, ENTSYS_DATA_TYPE_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_INT);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}
