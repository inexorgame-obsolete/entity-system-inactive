// Inexor entity system
// (c)2018-2019 Inexor

#include "DataContainer.hpp"
#include <gtest/gtest.h>
#include <string>
#include <cstdint>
#include <glm/glm.hpp>

using namespace inexor;
using namespace entity_system;

TEST(DataContainer, test_value_types)
{
	auto bool_attribute = DataContainer{DataType::BOOL, false};
	EXPECT_EQ(std::get<DataType::BOOL>(bool_attribute.value.Value()), false);

	auto int_attribute = DataContainer{DataType::INT, 1};
	EXPECT_EQ(std::get<DataType::INT>(int_attribute.value.Value()), 1);

	auto big_int_attribute = DataContainer{DataType::BIG_INT, std::int64_t(7)};
	EXPECT_EQ(std::get<DataType::BIG_INT>(big_int_attribute.value.Value()), std::int64_t(7));

	auto double_attribute = DataContainer{DataType::DOUBLE, 1.0};
	EXPECT_EQ(std::get<DataType::DOUBLE>(double_attribute.value.Value()), 1.0);

	auto float_attribute = DataContainer{DataType::FLOAT, 1.0f};
	EXPECT_EQ(std::get<DataType::FLOAT>(float_attribute.value.Value()), 1.0f);

	auto string_attribute = DataContainer{DataType::STRING, std::string("hello inexor")};
	EXPECT_EQ(std::get<DataType::STRING>(string_attribute.value.Value()), std::string("hello inexor"));
}

TEST(DataContainer, test_assigment)
{
	DataContainer attribute = {DataType::STRING, std::string("heya")};
	std::string a = std::get<DataType::STRING>(attribute.value.Value());
	EXPECT_EQ(a, std::string("heya"));
}

//TEST(DataContainer, test_glm_vectors)
//{
//    DataContainer vec3_attribute = {DataType::VEC3, glm::vec3(0, 0, 0)};
//    auto v3 = std::get<DataType::VEC3>(vec3_attribute.value.Value());
//    EXPECT_EQ(v3, glm::vec3(0, 0, 0));
//
//    DataContainer vec4_attribute = {DataType::VEC4, glm::vec4(glm::vec3(0, 0, 0), 0)};
//    auto v4 = std::get<DataType::VEC4>(vec4_attribute.value.Value());
//    EXPECT_EQ(v4, glm::vec4(glm::vec3(0, 0, 0), 0));
//}
