#include <ui/factories/WindowFactory.hpp>

#include <type-system/types/ui/Window.hpp>

namespace inexor::ui {

using Window = entity_system::type_system::Window;

WindowFactory::WindowFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, EntityInstanceManagerPtr entity_instance_manager)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
    this->entity_instance_manager = std::move(entity_instance_manager);
}

WindowFactory::~WindowFactory() = default;

std::string WindowFactory::get_component_name()
{
    return "WindowFactory";
}

EntityInstancePtrOpt WindowFactory::create_instance(int id, const std::string &title, int x, int y, int width, int height)
{
    return this->entity_instance_builder_factory
        ->get_builder(Window::TYPE_NAME)
        ->attribute(Window::ID, id)
        ->attribute(Window::TITLE, title)
        ->attribute(Window::POSITION_X, x)
        ->attribute(Window::POSITION_Y, y)
        ->attribute(Window::WIDTH, width)
        ->attribute(Window::HEIGHT, height)
        ->attribute(Window::OPACITY, 1.0f)
        ->attribute(Window::VISIBLE, true)
        ->attribute(Window::FULLSCREEN, false)
        ->attribute(Window::RESTORE_WIDTH, width)
        ->attribute(Window::RESTORE_HEIGHT, height)
        ->attribute(Window::ICONIFIED, false)
        ->attribute(Window::MAXIMIZED, false)
        ->attribute(Window::FOCUSED, false)
        ->attribute(Window::VSYNC, true)
        ->attribute(Window::FPS, 60.0f)
        ->build();
}

EntityInstancePtrOpt WindowFactory::create_instance(int id, const std::string &title, int x, int y, int width, int height, float opacity)
{
    return this->entity_instance_builder_factory
        ->get_builder(Window::TYPE_NAME)
        ->attribute(Window::ID, id)
        ->attribute(Window::TITLE, title)
        ->attribute(Window::POSITION_X, x)
        ->attribute(Window::POSITION_Y, y)
        ->attribute(Window::WIDTH, width)
        ->attribute(Window::HEIGHT, height)
        ->attribute(Window::OPACITY, opacity)
        ->attribute(Window::VISIBLE, true)
        ->attribute(Window::FULLSCREEN, false)
        ->attribute(Window::RESTORE_WIDTH, width)
        ->attribute(Window::RESTORE_HEIGHT, height)
        ->attribute(Window::ICONIFIED, false)
        ->attribute(Window::MAXIMIZED, false)
        ->attribute(Window::FOCUSED, false)
        ->attribute(Window::VSYNC, true)
        ->attribute(Window::FPS, 60.0f)
        ->build();
}

EntityInstancePtrOpt WindowFactory::create_instance(int id, const std::string &title, int x, int y, int width, int height, float opacity, bool visible, bool fullscreen, bool iconified, bool maximized, bool focused, bool vsync, float fps)
{
    return this->entity_instance_builder_factory
        ->get_builder(Window::TYPE_NAME)
        ->attribute(Window::ID, id)
        ->attribute(Window::TITLE, title)
        ->attribute(Window::POSITION_X, x)
        ->attribute(Window::POSITION_Y, y)
        ->attribute(Window::WIDTH, width)
        ->attribute(Window::HEIGHT, height)
        ->attribute(Window::OPACITY, opacity)
        ->attribute(Window::VISIBLE, visible)
        ->attribute(Window::FULLSCREEN, fullscreen)
        ->attribute(Window::RESTORE_WIDTH, width)
        ->attribute(Window::RESTORE_HEIGHT, height)
        ->attribute(Window::ICONIFIED, iconified)
        ->attribute(Window::MAXIMIZED, maximized)
        ->attribute(Window::FOCUSED, focused)
        ->attribute(Window::VSYNC, vsync)
        ->attribute(Window::FPS, fps)
        ->build();
}

} // namespace inexor::ui
