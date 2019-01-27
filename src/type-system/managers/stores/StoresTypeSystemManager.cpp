// Inexor entity system
// (c)2018 Inexor

#include "StoresTypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	StoresTypeSystemManager::StoresTypeSystemManager(
		shared_ptr<IntStoreEntityTypeProvider> int_store_entity_type_provider,
		shared_ptr<FloatStoreEntityTypeProvider> float_store_entity_type_provider,
		shared_ptr<StringStoreEntityTypeProvider> string_store_entity_type_provider,
		shared_ptr<IntStoreFactory> int_store_factory,
		shared_ptr<FloatStoreFactory> float_store_factory,
		shared_ptr<StringStoreFactory> string_store_factory
	)
	{
		this->int_store_entity_type_provider = int_store_entity_type_provider;
		this->float_store_entity_type_provider = float_store_entity_type_provider;
		this->string_store_entity_type_provider = string_store_entity_type_provider;
		this->int_store_factory = int_store_factory;
		this->float_store_factory = float_store_factory;
		this->string_store_factory = string_store_factory;
	}

	StoresTypeSystemManager::~StoresTypeSystemManager()
	{
	}

	void StoresTypeSystemManager::init()
	{
	}

}
}
}
