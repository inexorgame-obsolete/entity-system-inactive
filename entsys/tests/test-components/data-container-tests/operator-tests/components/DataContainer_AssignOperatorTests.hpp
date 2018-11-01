// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_INT)
{
	int IntegerTestValue = 1994;
	// Use implicit type conversion.
	DataContainer IntegerContainer = IntegerTestValue;
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_int(), IntegerTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_BIG_INT)
{
	std::int64_t BigIntegerTestValue = 199499143;
	// Use implicit type conversion.
	DataContainer IntegerContainer = BigIntegerTestValue;
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
	ASSERT_EQ(IntegerContainer.get_int64(), BigIntegerTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_FLOAT)
{
	float FloatTestValue = 1337.0f;
	// Use implicit type conversion.
	DataContainer FloatContainer = FloatTestValue;
	ASSERT_EQ(FloatContainer.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(FloatContainer.get_float(), FloatTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_STRING)
{
	std::string StringTestValue = std::string("This is an example.");
	// Use implicit type conversion.
	DataContainer StringContainer = StringTestValue;
	ASSERT_EQ(StringContainer.get_data_type(), ENTSYS_DATA_TYPE_STRING);
	ASSERT_EQ(StringContainer.get_string(), StringTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_DOUBLE)
{
	double DoubleTestValue = 329895032542343.2323;
	// Use implicit type conversion.
	DataContainer DoubleContainer = DoubleTestValue;
	ASSERT_EQ(DoubleContainer.get_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
	ASSERT_EQ(DoubleContainer.get_double(), DoubleTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_BOOL)
{
	bool BoolTestValue = false;
	// Use implicit type conversion.
	DataContainer BoolContainer = BoolTestValue;
	ASSERT_EQ(BoolContainer.get_data_type(), ENTSYS_DATA_TYPE_BOOL);
	ASSERT_EQ(BoolContainer.get_bool(), BoolTestValue);
}
