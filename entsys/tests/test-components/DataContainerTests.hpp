// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

#include "../../data-container/DataTypes.hpp"
#include "../../data-container/DataContainer.hpp"
using namespace inexor::entity_system;


// Test constructor calls of DataContainer by passing data type.

TEST(DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_INT);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
}

TEST(DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_BIG_INT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_BIG_INT);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
}

TEST(DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_FLOAT)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_FLOAT);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
}

TEST(DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_STRING)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_STRING);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_STRING);
}

TEST(DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_DOUBLE)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_DOUBLE);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
}

TEST(DataContainer_DataTypeConstructor, ENTSYS_DATA_TYPE_BOOL)
{
	DataContainer IntegerContainer(ENTSYS_DATA_TYPE_BOOL);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BOOL);
}



// Test constructor calls of DataContainer by passing value.

TEST(DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_INT)
{
	int IntegerTestValue = 1994;
	DataContainer IntegerContainer(IntegerTestValue);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
	EXPECT_EQ(IntegerContainer.get_int(), IntegerTestValue);
}

TEST(DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_BIG_INT)
{
	std::int64_t BigIntegerTestValue = 199499143;
	DataContainer IntegerContainer(BigIntegerTestValue);
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
	EXPECT_EQ(IntegerContainer.get_int64(), BigIntegerTestValue);
}

TEST(DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_FLOAT)
{
	float FloatTestValue = 1337.0f;
	DataContainer FloatContainer(FloatTestValue);
	EXPECT_EQ(FloatContainer.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	EXPECT_EQ(FloatContainer.get_float(), FloatTestValue);
}

TEST(DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_STRING)
{
	std::string StringTestValue = std::string("This is an example.");
	DataContainer StringContainer(StringTestValue);
	EXPECT_EQ(StringContainer.get_data_type(), ENTSYS_DATA_TYPE_STRING);
	EXPECT_EQ(StringContainer.get_string(), StringTestValue);
}

TEST(DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_DOUBLE)
{
	double DoubleTestValue = 329895032542343.2323;
	DataContainer DoubleContainer(DoubleTestValue);
	EXPECT_EQ(DoubleContainer.get_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
	EXPECT_EQ(DoubleContainer.get_double(), DoubleTestValue);
}

TEST(DataContainer_DataValueConstructor, ENTSYS_DATA_TYPE_BOOL)
{
	bool BoolTestValue = false;
	DataContainer BoolContainer(BoolTestValue);
	EXPECT_EQ(BoolContainer.get_data_type(), ENTSYS_DATA_TYPE_BOOL);
	EXPECT_EQ(BoolContainer.get_bool(), BoolTestValue);
}



// Test operator = of DataContainer by passing value.

TEST(DataContainer_AssignOperator, ENTSYS_DATA_TYPE_INT)
{
	int IntegerTestValue = 1994;
	DataContainer IntegerContainer = IntegerTestValue;
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_INT);
	EXPECT_EQ(IntegerContainer.get_int(), IntegerTestValue);
}

TEST(DataContainer_AssignOperator, ENTSYS_DATA_TYPE_BIG_INT)
{
	std::int64_t BigIntegerTestValue = 199499143;
	DataContainer IntegerContainer = BigIntegerTestValue;
	EXPECT_EQ(IntegerContainer.get_data_type(), ENTSYS_DATA_TYPE_BIG_INT);
	EXPECT_EQ(IntegerContainer.get_int64(), BigIntegerTestValue);
}

TEST(DataContainer_AssignOperator, ENTSYS_DATA_TYPE_FLOAT)
{
	float FloatTestValue = 1337.0f;
	DataContainer FloatContainer = FloatTestValue;
	EXPECT_EQ(FloatContainer.get_data_type(), ENTSYS_DATA_TYPE_FLOAT);
	EXPECT_EQ(FloatContainer.get_float(), FloatTestValue);
}

TEST(DataContainer_AssignOperator, ENTSYS_DATA_TYPE_STRING)
{
	std::string StringTestValue = std::string("This is an example.");
	DataContainer StringContainer = StringTestValue;
	EXPECT_EQ(StringContainer.get_data_type(), ENTSYS_DATA_TYPE_STRING);
	EXPECT_EQ(StringContainer.get_string(), StringTestValue);
}

TEST(DataContainer_AssignOperator, ENTSYS_DATA_TYPE_DOUBLE)
{
	double DoubleTestValue = 329895032542343.2323;
	DataContainer DoubleContainer = DoubleTestValue;
	EXPECT_EQ(DoubleContainer.get_data_type(), ENTSYS_DATA_TYPE_DOUBLE);
	EXPECT_EQ(DoubleContainer.get_double(), DoubleTestValue);
}

TEST(DataContainer_AssignOperator, ENTSYS_DATA_TYPE_BOOL)
{
	bool BoolTestValue = false;
	DataContainer BoolContainer = BoolTestValue;
	EXPECT_EQ(BoolContainer.get_data_type(), ENTSYS_DATA_TYPE_BOOL);
	EXPECT_EQ(BoolContainer.get_bool(), BoolTestValue);
}
