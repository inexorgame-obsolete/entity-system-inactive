// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once


TEST(Test_DataContainer_ArithmeticOperator_Decrement, ENTSYS_DATA_TYPE_INT)
{
	int example_value = 8765;
	DataContainer IncrementMe(example_value);
	ASSERT_EQ(IncrementMe.get_data_type(), ENTSYS_DATA_TYPE_INT);
	// Increment DataContainer!
	IncrementMe--;
	ASSERT_EQ(IncrementMe.get_int(), (example_value-1));
}


TEST(Test_DataContainer_ArithmeticOperator_Decrement, ENTSYS_DATA_TYPE_BIG_INT)
{
	std::int64_t example_value = 2348290342;
	DataContainer IncrementMe(example_value);
	ASSERT_EQ(IncrementMe.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
	// Increment DataContainer!
	IncrementMe--;
	ASSERT_EQ(IncrementMe.get_int64(), (example_value-1));
}


TEST(Test_DataContainer_ArithmeticOperator_Decrement, ENTSYS_DATA_TYPE_DOUBLE)
{
	double example_value = 345632.34;
	DataContainer IncrementMe(example_value);
	ASSERT_EQ(IncrementMe.get_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
	// Increment DataContainer!
	IncrementMe--;
	ASSERT_EQ(IncrementMe.get_double(), (example_value-1));
}


TEST(Test_DataContainer_ArithmeticOperator_Decrement, ENTSYS_DATA_TYPE_FLOAT)
{
	float example_value = 23434235.9654f;
	DataContainer IncrementMe(example_value);
	ASSERT_EQ(IncrementMe.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	// Decrement DataContainer!
	IncrementMe--;
	ASSERT_EQ(IncrementMe.get_float(), (example_value-1));
}
