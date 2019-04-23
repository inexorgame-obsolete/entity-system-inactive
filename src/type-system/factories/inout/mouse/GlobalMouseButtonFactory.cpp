#include "GlobalMouseButtonFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	GlobalMouseButtonFactory::GlobalMouseButtonFactory(
		GlobalMouseButtonEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	GlobalMouseButtonFactory::~GlobalMouseButtonFactory()
	{
	}

	void GlobalMouseButtonFactory::init()
	{
	}

	EntityInstancePtrOpt GlobalMouseButtonFactory::create_instance(const int& button)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(GlobalMouseButtonEntityTypeProvider::GLOBAL_MOUSE_BUTTON_NUMBER, button)
			->attribute(GlobalMouseButtonEntityTypeProvider::GLOBAL_MOUSE_BUTTON_ACTION, 0)
			->attribute(GlobalMouseButtonEntityTypeProvider::GLOBAL_MOUSE_BUTTON_MODS, 0)
			->build();
	}

}
}
}
