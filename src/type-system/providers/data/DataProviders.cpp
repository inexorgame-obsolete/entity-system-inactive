#include "DataProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	DataProviders::DataProviders(
		ConstantProvidersPtr constant_providers,
		ConverterProvidersPtr converter_providers,
		StoreProvidersPtr store_providers
	)
	{
		this->constant_providers = constant_providers;
		this->converter_providers = converter_providers;
		this->store_providers = store_providers;
	}

	DataProviders::~DataProviders()
	{
	}

	void DataProviders::init()
	{
		constant_providers->init();
		converter_providers->init();
		store_providers->init();
	}

}
}
}
