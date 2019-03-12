#include "TypeSystemFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TypeSystemFactories::TypeSystemFactories(
		ArithmeticFactoriesPtr arithmetic_factories,
		ComparisonFactoriesPtr comparison_factories,
		ConstantFactoriesPtr constant_factories,
		ConverterFactoriesPtr converter_factories,
		LoggerFactoriesPtr logger_factories,
		LogicalFactoriesPtr logical_factories,
		StoreFactoriesPtr store_factories,
		TrigonometricFactoriesPtr trigonometric_factories
	)
	{
		this->arithmetic_factories = arithmetic_factories;
		this->comparison_factories = comparison_factories;
		this->constant_factories = constant_factories;
		this->converter_factories = converter_factories;
		this->logger_factories = logger_factories;
		this->logical_factories = logical_factories;
		this->store_factories = store_factories;
		this->trigonometric_factories = trigonometric_factories;
	}

	TypeSystemFactories::~TypeSystemFactories()
	{
	}

	void TypeSystemFactories::init()
	{
		arithmetic_factories->init();
		comparison_factories->init();
		constant_factories->init();
		converter_factories->init();
		logger_factories->init();
		logical_factories->init();
		store_factories->init();
		trigonometric_factories->init();
	}

}
}
}
