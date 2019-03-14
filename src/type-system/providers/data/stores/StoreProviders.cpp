#include "StoreProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	StoreProviders::StoreProviders(
		FloatStoreEntityTypeProviderPtr float_store_entity_type_provider,
		IntStoreEntityTypeProviderPtr int_store_entity_type_provider,
		StringStoreEntityTypeProviderPtr string_store_entity_type_provider
	)
	{
		this->float_store_entity_type_provider = float_store_entity_type_provider;
		this->int_store_entity_type_provider = int_store_entity_type_provider;
		this->string_store_entity_type_provider = string_store_entity_type_provider;
	}

	StoreProviders::~StoreProviders()
	{
	}

	void StoreProviders::init()
	{
	}

}
}
}
