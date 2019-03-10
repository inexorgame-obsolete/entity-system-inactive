#include "TypeSystemModule.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {


	TypeSystemModule::TypeSystemModule(
		TypeSystemFactoriesPtr type_system_factories,
		TypeSystemProvidersPtr type_system_providers
	)
	{
		this->type_system_factories = type_system_factories;
		this->type_system_providers = type_system_providers;
	}

	TypeSystemModule::~TypeSystemModule()
	{
	}

	void TypeSystemModule::init()
	{
		type_system_factories->init();
		type_system_providers->init();
	}


}
}
}
