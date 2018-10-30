// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once


TEST(Test_DataContainer_SetDataType, ENTSYS_DATA_TYPE_UNDEFINED)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_UNDEFINED);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_UNDEFINED);
	// Change the data type.
	IntegerContainer.set_data_type(ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}


TEST(Test_DataContainer_SetDataType, ENTSYS_DATA_TYPE_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
	// Change the data type.
	IntegerContainer.set_data_type(ENTSYS_DATA_TYPE_BIG_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
}


TEST(Test_DataContainer_SetDataType, ENTSYS_DATA_TYPE_BIG_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_BIG_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
	// Change the data type.
	IntegerContainer.set_data_type(ENTSYS_DATA_TYPE_STRING);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_STRING);
}


TEST(Test_DataContainer_SetDataType, ENTSYS_DATA_TYPE_FLOAT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	// Change the data type.
	IntegerContainer.set_data_type(ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}


TEST(Test_DataContainer_SetDataType, ENTSYS_DATA_TYPE_STRING)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_STRING);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_STRING);
	// Change the data type.
	IntegerContainer.set_data_type(ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}


TEST(Test_DataContainer_SetDataType, ENTSYS_DATA_TYPE_DOUBLE)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_DOUBLE);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
	// Change the data type.
	IntegerContainer.set_data_type(ENTSYS_DATA_TYPE_BOOL);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BOOL);
}


TEST(Test_DataContainer_SetDataType, ENTSYS_DATA_TYPE_BOOL)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_BOOL);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BOOL);
	// Change the data type.
	IntegerContainer.set_data_type(ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}
