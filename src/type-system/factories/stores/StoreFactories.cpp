#include "StoreFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	StoreFactories::StoreFactories(
		FloatStoreFactoryPtr float_store_factory,
		IntStoreFactoryPtr int_store_factory,
		StringStoreFactoryPtr string_store_factory
	)
	{
		this->float_store_factory = float_store_factory;
		this->int_store_factory = int_store_factory;
		this->string_store_factory = string_store_factory;
	}

	StoreFactories::~StoreFactories()
	{
	}

	void StoreFactories::init()
	{
		float_store_factory->init();
		int_store_factory->init();
		string_store_factory->init();
	}

}
}
}
