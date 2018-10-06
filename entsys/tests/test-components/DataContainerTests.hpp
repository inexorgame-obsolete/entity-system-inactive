// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

#include "../../data-container/DataTypes.hpp"
#include "../../data-container/DataContainer.hpp"
using namespace inexor::entity_system;


// Test constructor calls of DataContainer by passing data type.

TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_INT);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_BIG_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_BIG_INT);
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_FLOAT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_FLOAT);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_STRING)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_STRING);
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_STRING);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_DOUBLE)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_DOUBLE);
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
}


TEST(Test_DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_BOOL)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_BOOL);
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_BOOL);
}


// Test constructor calls of DataContainer by passing value.

TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_INT)
{
	int IntegerTestValue = 1994;
	DataContainer IntegerContainer(IntegerTestValue);
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_int(), IntegerTestValue);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_BIG_INT)
{
	std::int64_t BigIntegerTestValue = 199499143;
	DataContainer IntegerContainer(BigIntegerTestValue);
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
	ASSERT_EQ(IntegerContainer.get_int64(), BigIntegerTestValue);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_FLOAT)
{
	float FloatTestValue = 1337.0f;
	DataContainer FloatContainer(FloatTestValue);
	ASSERT_EQ(FloatContainer.get_container_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(FloatContainer.get_float(), FloatTestValue);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_STRING)
{
	std::string StringTestValue = std::string("This is an example.");
	DataContainer StringContainer(StringTestValue);
	ASSERT_EQ(StringContainer.get_container_data_type(), ENTSYS_DATA_TYPE_STRING);
	ASSERT_EQ(StringContainer.get_string(), StringTestValue);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_DOUBLE)
{
	double DoubleTestValue = 329895032542343.2323;
	DataContainer DoubleContainer(DoubleTestValue);
	ASSERT_EQ(DoubleContainer.get_container_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
	ASSERT_EQ(DoubleContainer.get_double(), DoubleTestValue);
}


TEST(Test_DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_BOOL)
{
	bool BoolTestValue = false;
	DataContainer BoolContainer(BoolTestValue);
	ASSERT_EQ(BoolContainer.get_container_data_type(), ENTSYS_DATA_TYPE_BOOL);
	ASSERT_EQ(BoolContainer.get_bool(), BoolTestValue);
}


// Test operator = of DataContainer by passing value.

TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_INT)
{
	int IntegerTestValue = 1994;
	DataContainer IntegerContainer = IntegerTestValue;
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_INT);
	ASSERT_EQ(IntegerContainer.get_int(), IntegerTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_BIG_INT)
{
	std::int64_t BigIntegerTestValue = 199499143;
	DataContainer IntegerContainer = BigIntegerTestValue;
	ASSERT_EQ(IntegerContainer.get_container_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
	ASSERT_EQ(IntegerContainer.get_int64(), BigIntegerTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_FLOAT)
{
	float FloatTestValue = 1337.0f;
	DataContainer FloatContainer = FloatTestValue;
	ASSERT_EQ(FloatContainer.get_container_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	ASSERT_EQ(FloatContainer.get_float(), FloatTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_STRING)
{
	std::string StringTestValue = std::string("This is an example.");
	DataContainer StringContainer = StringTestValue;
	ASSERT_EQ(StringContainer.get_container_data_type(), ENTSYS_DATA_TYPE_STRING);
	ASSERT_EQ(StringContainer.get_string(), StringTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_DOUBLE)
{
	double DoubleTestValue = 329895032542343.2323;
	DataContainer DoubleContainer = DoubleTestValue;
	ASSERT_EQ(DoubleContainer.get_container_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
	ASSERT_EQ(DoubleContainer.get_double(), DoubleTestValue);
}


TEST(Test_DataContainer_AssignOperator, ENTSYS_DATA_TYPE_BOOL)
{
	bool BoolTestValue = false;
	DataContainer BoolContainer = BoolTestValue;
	ASSERT_EQ(BoolContainer.get_container_data_type(), ENTSYS_DATA_TYPE_BOOL);
	ASSERT_EQ(BoolContainer.get_bool(), BoolTestValue);
}
