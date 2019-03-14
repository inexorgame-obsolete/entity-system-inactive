#include "DataFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	DataFactories::DataFactories(
		ConstantFactoriesPtr constant_factories,
		ConverterFactoriesPtr converter_factories,
		StoreFactoriesPtr store_factories
	)
	{
		this->constant_factories = constant_factories;
		this->converter_factories = converter_factories;
		this->store_factories = store_factories;
	}

	DataFactories::~DataFactories()
	{
	}

	void DataFactories::init()
	{
		constant_factories->init();
		converter_factories->init();
		store_factories->init();
	}

}
}
}
