// Inexor entity system
// (c)2018-2019 Inexor

#include "DataContainer.hpp"
#include <gtest/gtest.h>
#include <string>
#include <cstdint>

using namespace inexor;
using namespace entity_system;

TEST(DataContainer, test_value_types)
{
    auto bool_attribute = DataContainer{ENTSYS_DATA_TYPE_BOOL, false};
    EXPECT_EQ(std::get<ENTSYS_DATA_TYPE_BOOL>(bool_attribute.value), false);

    auto int_attribute = DataContainer{ENTSYS_DATA_TYPE_INT, 1};
    EXPECT_EQ(std::get<ENTSYS_DATA_TYPE_INT>(int_attribute.value), 1);

    auto big_int_attribute = DataContainer{ENTSYS_DATA_TYPE_BIG_INT, std::int64_t(7)};
    EXPECT_EQ(std::get<ENTSYS_DATA_TYPE_BIG_INT>(big_int_attribute.value), std::int64_t(7));

    auto double_attribute = DataContainer{ENTSYS_DATA_TYPE_DOUBLE, 1.0};
    EXPECT_EQ(std::get<ENTSYS_DATA_TYPE_DOUBLE>(double_attribute.value), 1.0);

    auto float_attribute = DataContainer{ENTSYS_DATA_TYPE_FLOAT, 1.0f};
    EXPECT_EQ(std::get<ENTSYS_DATA_TYPE_FLOAT>(float_attribute.value), 1.0f);

    auto string_attribute = DataContainer{ENTSYS_DATA_TYPE_STRING, std::string("hello inexor")};
    EXPECT_EQ(std::get<ENTSYS_DATA_TYPE_STRING>(string_attribute.value), std::string("hello inexor"));
}

TEST(DataContainer, test_assigment)
{
    DataContainer attribute = {ENTSYS_DATA_TYPE_STRING, std::string("heya")};
    std::string a = std::get<ENTSYS_DATA_TYPE_STRING>(attribute.value);
    EXPECT_EQ(a, std::string("heya"));
}
