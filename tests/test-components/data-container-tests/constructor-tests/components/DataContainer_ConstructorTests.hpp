// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

// Test constructor calls of DataContainer by passing data type.

TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_UNDEFINED)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_UNDEFINED);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_UNDEFINED);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_BIG_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_BIG_INT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_FLOAT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_STRING)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_STRING);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_STRING);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_DOUBLE)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_DOUBLE);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_BOOL)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_BOOL);
	ASSERT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BOOL);
}



// Test constructor calls of DataContainer by passing data.


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_BIG_INT)
{
	std::int64_t big_integer = 1230724031398;
	DataContainer BigIntCont(big_integer);
	ASSERT_EQ(BigIntCont.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
	std::int64_t big_integer_test = BigIntCont.get_int64();
	ASSERT_EQ(big_integer_test, big_integer);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_BOOL)
{
	bool bool_val = false;
	DataContainer BoolContainer(bool_val);
	ASSERT_EQ(BoolContainer.get_data_type(), ENTSYS_DATA_TYPE_BOOL);
	bool bool_test = BoolContainer.get_bool();
	ASSERT_EQ(bool_test, bool_val);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_DOUBLE)
{
	double dbl_val = 21345346.23423;
	DataContainer DoubleContainer(dbl_val);
	ASSERT_EQ(DoubleContainer.get_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
	double double_test = DoubleContainer.get_double();
	ASSERT_EQ(double_test, dbl_val);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_FLOAT)
{
	float flt_val = 212345.23f;
	DataContainer FloatContainer(flt_val);
	ASSERT_EQ(FloatContainer.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	float float_test = FloatContainer.get_float();
	ASSERT_EQ(float_test, flt_val);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_INT)
{
	int int_val = 21234;
	DataContainer IntContainer(int_val);
	ASSERT_EQ(IntContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
	int int_test = IntContainer.get_int();
	ASSERT_EQ(int_test, int_val);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_STRING)
{
	std::string str_val = "abcdefghijklmnopqrstuvwxyz1234567890?!\"§$%&/()=?";
	DataContainer StringContainer(str_val);
	ASSERT_EQ(StringContainer.get_data_type(), ENTSYS_DATA_TYPE_STRING);
	std::string str_test = StringContainer.get_string();
	ASSERT_EQ(str_test.compare(str_val), 0);
}
