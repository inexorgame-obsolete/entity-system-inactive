// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once


// Add an integer value to a DataContainer of type INT.
TEST(Test_DataContainer_PlusOperator_1, ENTSYS_DATA_TYPE_INT)
{
	int example_value = 8765;
	DataContainer IntCont(example_value);
	ASSERT_EQ(IntCont.get_data_type(), ENTSYS_DATA_TYPE_INT);

	int add_this_value = 23422;
	// This is what we are expecting as result.
	int operation_result = example_value + static_cast<int>(add_this_value);

	// Use DataContainer::operator+
	IntCont = IntCont + add_this_value;
	ASSERT_EQ(IntCont.get_int(), operation_result);
}


// Add an double value to a DataContainer of type INT.
TEST(Test_DataContainer_PlusOperator_2, ENTSYS_DATA_TYPE_DOUBLE)
{
	int example_value = 23456;
	DataContainer IntCont(example_value);
	ASSERT_EQ(IntCont.get_data_type(), ENTSYS_DATA_TYPE_INT);

	double add_this_value = 23422.0;
	// This is what we are expecting as result.
	int operation_result = example_value + static_cast<int>(add_this_value);

	// Use DataContainer::operator+
	IntCont = IntCont + add_this_value;
	ASSERT_EQ(IntCont.get_int(), operation_result);
}


// Add an float value to a DataContainer of type INT.
TEST(Test_DataContainer_PlusOperator_3, ENTSYS_DATA_TYPE_FLOAT)
{
	int example_value = 567654;
	DataContainer IntCont(example_value);
	ASSERT_EQ(IntCont.get_data_type(), ENTSYS_DATA_TYPE_INT);

	float add_this_value = 234824.0f;
	// This is what we are expecting as result.
	int operation_result = example_value + static_cast<int>(add_this_value);

	// Use DataContainer::operator+
	IntCont = IntCont + add_this_value;
	ASSERT_EQ(IntCont.get_int(), operation_result);
}


// Add an std::int64_t value to a DataContainer of type INT.
TEST(Test_DataContainer_PlusOperator_4, ENTSYS_DATA_TYPE_BIG_INT)
{
	int example_value = 567654;
	DataContainer IntCont(example_value);
	ASSERT_EQ(IntCont.get_data_type(), ENTSYS_DATA_TYPE_INT);

	std::int64_t add_this_value = 2342387409;
	// This is what we are expecting as result.
	int operation_result = example_value + static_cast<int>(add_this_value);

	// Use DataContainer::operator+
	IntCont = IntCont + add_this_value;
	ASSERT_EQ(IntCont.get_int(), operation_result);
}


// Add an DataContainer value to a DataContainer of type INT.
TEST(Test_DataContainer_PlusOperator_5, ENTSYS_DATA_TYPE_INT)
{
	int example_value = 567654;
	DataContainer IntCont1(example_value);
	ASSERT_EQ(IntCont1.get_data_type(), ENTSYS_DATA_TYPE_INT);

	int add_this_value = 2342387409;
	DataContainer IntCont2(add_this_value);
	ASSERT_EQ(IntCont2.get_data_type(), ENTSYS_DATA_TYPE_INT);
	
	// This is what we are expecting as result.
	int operation_result = example_value + static_cast<int>(add_this_value);

	// Use DataContainer::operator+
	IntCont1 = IntCont1 + IntCont2;
	
	ASSERT_EQ(IntCont1.get_int(), operation_result);
}


// Create a sum of 5 DataContainers of type INT.
TEST(Test_DataContainer_PlusOperator_6, ENTSYS_DATA_TYPE_INT)
{
	int summand_1 = -33;
	int summand_2 = 5678654;
	int summand_3 = -6531;
	int summand_4 = 769126;
	int summand_5 = -2342;
	
	DataContainer IntCont1(summand_1);
	DataContainer IntCont2(summand_2);
	DataContainer IntCont3(summand_3);
	DataContainer IntCont4(summand_4);
	DataContainer IntCont5(summand_5);

	ASSERT_EQ(IntCont1.get_data_type(), ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntCont2.get_data_type(), ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntCont3.get_data_type(), ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntCont4.get_data_type(), ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntCont5.get_data_type(), ENTSYS_DATA_TYPE_INT);
	
	// This is what we are expecting as result.
	int operation_result = summand_1 + summand_2 + summand_3 + summand_4 + summand_5;

	// Use DataContainer::operator+
	IntCont1 = IntCont1 + IntCont2 + IntCont3 + IntCont4 + IntCont5;
	
	ASSERT_EQ(IntCont1.get_int(), operation_result);
}


// Create a sum of 5 DataContainers of type FLOAT.
TEST(Test_DataContainer_PlusOperator_6, ENTSYS_DATA_TYPE_FLOAT)
{
	float summand_1 = -2345.0f;
	float summand_2 = 56324.0f;
	float summand_3 = -234345.0f;
	float summand_4 = 234623.0f;
	float summand_5 = -2.0f;
	
	DataContainer FloatCont1(summand_1);
	DataContainer FloatCont2(summand_2);
	DataContainer FloatCont3(summand_3);
	DataContainer FloatCont4(summand_4);
	DataContainer FloatCont5(summand_5);

	ASSERT_EQ(FloatCont1.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(FloatCont2.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(FloatCont3.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(FloatCont4.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(FloatCont5.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	
	// This is what we are expecting as result.
	float operation_result = summand_1 + summand_2 + summand_3 + summand_4 + summand_5;

	// Use DataContainer::operator+
	FloatCont1 = FloatCont1 + FloatCont2 + FloatCont3 + FloatCont4 + FloatCont5;
	
	ASSERT_EQ(FloatCont1.get_float(), operation_result);
}
