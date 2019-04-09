#include "WindowFactory.hpp"

namespace inexor {
namespace renderer {

	WindowFactory::WindowFactory(
		WindowEntityTypeProviderPtr window_entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory,
		EntityInstanceManagerPtr entity_instance_manager
	)
	{
		this->window_entity_type_provider = window_entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
		this->entity_instance_manager = entity_instance_manager;
	}

	WindowFactory::~WindowFactory()
	{
	}

	EntityInstancePtrOpt WindowFactory::create_instance(std::string title, int x, int y, int width, int height)
	{
		return this->entity_instance_builder_factory->get_builder()
		->type(window_entity_type_provider->get_type())
		->attribute(WindowEntityTypeProvider::WINDOW_TITLE, title)
		->attribute(WindowEntityTypeProvider::WINDOW_POSITION_X, x)
		->attribute(WindowEntityTypeProvider::WINDOW_POSITION_Y, y)
		->attribute(WindowEntityTypeProvider::WINDOW_WIDTH, width)
		->attribute(WindowEntityTypeProvider::WINDOW_HEIGHT, height)
		->attribute(WindowEntityTypeProvider::WINDOW_FULLSCREEN, false)
		->attribute(WindowEntityTypeProvider::WINDOW_ICONIFIED, false)
		->attribute(WindowEntityTypeProvider::WINDOW_MAXIMIZED, false)
		->attribute(WindowEntityTypeProvider::WINDOW_FOCUSED, false)
		->build();
	}

}
}
