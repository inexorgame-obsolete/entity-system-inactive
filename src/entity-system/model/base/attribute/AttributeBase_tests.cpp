#include <gtest/gtest.h>
#include "AttributeBase.hpp"

using namespace inexor::entity_system;

TEST(AttributeBase, ConstructorTestInt)
{
	class WeightAttribute : public AttributeBase
	{
	public:

		WeightAttribute() : AttributeBase(DataType::INT, Features::ENGINE_INPUT)
		{
		}

	};

	std::shared_ptr<WeightAttribute> weight_test = std::make_shared<WeightAttribute>();

	EXPECT_EQ(weight_test->get_attribute_data_type(), DataType::INT);

	EXPECT_EQ(weight_test->get_attribute_features(), Features::ENGINE_INPUT);
}


TEST(AttributeBase, ConstructorTestBool)
{
	class PresidentAttribute : public AttributeBase
	{
	public:

		PresidentAttribute() : AttributeBase(DataType::BOOL, Features::ENGINE_INPUT)
		{
		}

	};

	std::shared_ptr<PresidentAttribute> weight_test = std::make_shared<PresidentAttribute>();

	EXPECT_EQ(weight_test->get_attribute_data_type(), DataType::BOOL);

	EXPECT_EQ(weight_test->get_attribute_features(), Features::ENGINE_INPUT);
}


TEST(AttributeBase, ConstructorTestFloat)
{
	class HeightAttribute : public AttributeBase
	{
	public:

		HeightAttribute() : AttributeBase(DataType::FLOAT, Features::ENGINE_INPUT)
		{
		}

	};

	std::shared_ptr<HeightAttribute> weight_test = std::make_shared<HeightAttribute>();

	EXPECT_EQ(weight_test->get_attribute_data_type(), DataType::FLOAT);

	EXPECT_EQ(weight_test->get_attribute_features(), Features::ENGINE_INPUT);
}


TEST(AttributeBase, ConstructorTestBigInt)
{
	class PopulationAttribute : public AttributeBase
	{
	public:

		PopulationAttribute() : AttributeBase(DataType::BIG_INT, Features::ENGINE_INPUT)
		{
		}

	};

	std::shared_ptr<PopulationAttribute> weight_test = std::make_shared<PopulationAttribute>();

	EXPECT_EQ(weight_test->get_attribute_data_type(), DataType::BIG_INT);

	EXPECT_EQ(weight_test->get_attribute_features(), Features::ENGINE_INPUT);
}


TEST(AttributeBase, ConstructorTestDouble)
{
	class DistanceAttribute : public AttributeBase
	{
	public:

		DistanceAttribute() : AttributeBase(DataType::DOUBLE, Features::ENGINE_INPUT)
		{
		}

	};

	std::shared_ptr<DistanceAttribute> weight_test = std::make_shared<DistanceAttribute>();

	EXPECT_EQ(weight_test->get_attribute_data_type(), DataType::DOUBLE);

	EXPECT_EQ(weight_test->get_attribute_features(), Features::ENGINE_INPUT);
}
