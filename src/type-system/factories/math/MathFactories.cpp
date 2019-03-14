#include "MathFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	MathFactories::MathFactories(
		ArithmeticFactoriesPtr arithmetic_factories,
		TrigonometricFactoriesPtr trigonometric_factories
	)
	{
		this->arithmetic_factories = arithmetic_factories;
		this->trigonometric_factories = trigonometric_factories;
	}

	MathFactories::~MathFactories()
	{
	}

	void MathFactories::init()
	{
		arithmetic_factories->init();
		trigonometric_factories->init();
	}

}
}
}
