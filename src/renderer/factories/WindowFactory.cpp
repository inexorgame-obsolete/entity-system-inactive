#include "WindowFactory.hpp"

namespace inexor::renderer {

WindowFactory::WindowFactory(WindowEntityTypeProviderPtr window_entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, EntityInstanceManagerPtr entity_instance_manager)
{
    this->window_entity_type_provider = std::move(window_entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
    this->entity_instance_manager = std::move(entity_instance_manager);
}

WindowFactory::~WindowFactory()
{
}

EntityInstancePtrOpt WindowFactory::create_instance(int id, const std::string &title, int x, int y, int width, int height)
{
    return this->entity_instance_builder_factory->get_builder()
        ->type(window_entity_type_provider->get_type())
        ->attribute(WindowEntityTypeProvider::WINDOW_ID, id)
        ->attribute(WindowEntityTypeProvider::WINDOW_TITLE, title)
        ->attribute(WindowEntityTypeProvider::WINDOW_POSITION_X, x)
        ->attribute(WindowEntityTypeProvider::WINDOW_POSITION_Y, y)
        ->attribute(WindowEntityTypeProvider::WINDOW_WIDTH, width)
        ->attribute(WindowEntityTypeProvider::WINDOW_HEIGHT, height)
        ->attribute(WindowEntityTypeProvider::WINDOW_OPACITY, 1.0f)
        ->attribute(WindowEntityTypeProvider::WINDOW_VISIBLE, true)
        ->attribute(WindowEntityTypeProvider::WINDOW_FULLSCREEN, false)
        ->attribute(WindowEntityTypeProvider::WINDOW_RESTORE_WIDTH, width)
        ->attribute(WindowEntityTypeProvider::WINDOW_RESTORE_HEIGHT, height)
        ->attribute(WindowEntityTypeProvider::WINDOW_ICONIFIED, false)
        ->attribute(WindowEntityTypeProvider::WINDOW_MAXIMIZED, false)
        ->attribute(WindowEntityTypeProvider::WINDOW_FOCUSED, false)
        ->attribute(WindowEntityTypeProvider::WINDOW_VSYNC, true)
        ->attribute(WindowEntityTypeProvider::WINDOW_FPS, 60.0f)
        ->build();
}

EntityInstancePtrOpt WindowFactory::create_instance(int id, const std::string &title, int x, int y, int width, int height, float opacity)
{
    return this->entity_instance_builder_factory->get_builder()
        ->type(window_entity_type_provider->get_type())
        ->attribute(WindowEntityTypeProvider::WINDOW_ID, id)
        ->attribute(WindowEntityTypeProvider::WINDOW_TITLE, title)
        ->attribute(WindowEntityTypeProvider::WINDOW_POSITION_X, x)
        ->attribute(WindowEntityTypeProvider::WINDOW_POSITION_Y, y)
        ->attribute(WindowEntityTypeProvider::WINDOW_WIDTH, width)
        ->attribute(WindowEntityTypeProvider::WINDOW_HEIGHT, height)
        ->attribute(WindowEntityTypeProvider::WINDOW_OPACITY, opacity)
        ->attribute(WindowEntityTypeProvider::WINDOW_VISIBLE, true)
        ->attribute(WindowEntityTypeProvider::WINDOW_FULLSCREEN, false)
        ->attribute(WindowEntityTypeProvider::WINDOW_RESTORE_WIDTH, width)
        ->attribute(WindowEntityTypeProvider::WINDOW_RESTORE_HEIGHT, height)
        ->attribute(WindowEntityTypeProvider::WINDOW_ICONIFIED, false)
        ->attribute(WindowEntityTypeProvider::WINDOW_MAXIMIZED, false)
        ->attribute(WindowEntityTypeProvider::WINDOW_FOCUSED, false)
        ->attribute(WindowEntityTypeProvider::WINDOW_VSYNC, true)
        ->attribute(WindowEntityTypeProvider::WINDOW_FPS, 60.0f)
        ->build();
}

EntityInstancePtrOpt WindowFactory::create_instance(int id, const std::string &title, int x, int y, int width, int height, float opacity, bool visible, bool fullscreen, bool iconified, bool maximized, bool focused, bool vsync, float fps)
{
    return this->entity_instance_builder_factory->get_builder()
        ->type(window_entity_type_provider->get_type())
        ->attribute(WindowEntityTypeProvider::WINDOW_ID, id)
        ->attribute(WindowEntityTypeProvider::WINDOW_TITLE, title)
        ->attribute(WindowEntityTypeProvider::WINDOW_POSITION_X, x)
        ->attribute(WindowEntityTypeProvider::WINDOW_POSITION_Y, y)
        ->attribute(WindowEntityTypeProvider::WINDOW_WIDTH, width)
        ->attribute(WindowEntityTypeProvider::WINDOW_HEIGHT, height)
        ->attribute(WindowEntityTypeProvider::WINDOW_OPACITY, opacity)
        ->attribute(WindowEntityTypeProvider::WINDOW_VISIBLE, visible)
        ->attribute(WindowEntityTypeProvider::WINDOW_FULLSCREEN, fullscreen)
        ->attribute(WindowEntityTypeProvider::WINDOW_RESTORE_WIDTH, width)
        ->attribute(WindowEntityTypeProvider::WINDOW_RESTORE_HEIGHT, height)
        ->attribute(WindowEntityTypeProvider::WINDOW_ICONIFIED, iconified)
        ->attribute(WindowEntityTypeProvider::WINDOW_MAXIMIZED, maximized)
        ->attribute(WindowEntityTypeProvider::WINDOW_FOCUSED, focused)
        ->attribute(WindowEntityTypeProvider::WINDOW_VSYNC, vsync)
        ->attribute(WindowEntityTypeProvider::WINDOW_FPS, fps)
        ->build();
}

} // namespace inexor::renderer
