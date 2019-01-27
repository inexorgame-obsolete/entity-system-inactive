// Inexor entity system
// (c)2018 Inexor

#include "StoresTypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	StoresTypeSystemManager::StoresTypeSystemManager(
		shared_ptr<IntStoreEntityTypeProvider> int_store_entity_type_provider
	)
	{
		this->int_store_entity_type_provider = int_store_entity_type_provider;
	}

	StoresTypeSystemManager::~StoresTypeSystemManager()
	{
	}

}
}
}
