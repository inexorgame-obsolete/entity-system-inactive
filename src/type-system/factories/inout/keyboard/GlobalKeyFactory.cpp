#include "GlobalKeyFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	GlobalKeyFactory::GlobalKeyFactory(
		GlobalKeyEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	GlobalKeyFactory::~GlobalKeyFactory()
	{
	}

	void GlobalKeyFactory::init()
	{
	}

	EntityInstancePtrOpt GlobalKeyFactory::create_instance(const int& key)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(GlobalKeyEntityTypeProvider::GLOBAL_KEY_KEYCODE, key)
			->attribute(GlobalKeyEntityTypeProvider::GLOBAL_KEY_ACTION, 0)
			->attribute(GlobalKeyEntityTypeProvider::GLOBAL_KEY_MODS, 0)
			->build();
	}

}
}
}
