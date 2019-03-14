#include "TypeSystemModule.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TypeSystemModule::TypeSystemModule(
		TypeSystemProvidersPtr type_system_providers,
		TypeSystemFactoriesPtr type_system_factories
	)
	{
		this->type_system_providers = type_system_providers;
		this->type_system_factories = type_system_factories;
	}

	TypeSystemModule::~TypeSystemModule()
	{
	}

	void TypeSystemModule::init()
	{
		type_system_providers->init();
		type_system_factories->init();
	}

}
}
}
