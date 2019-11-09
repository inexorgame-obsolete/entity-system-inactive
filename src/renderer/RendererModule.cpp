#include "RendererModule.hpp"

// Statically import the magnum plugins
// This is the only place to do this!
#include "renderer/plugins/MagnumPlugins.cpp"

#include <GLFW/glfw3.h>

#include <utility>

namespace inexor::renderer {

RendererModule::RendererModule(FontManagerPtr font_manager, LoadingScreenPtr loading_screen, TriangleExamplePtr triangle_example)
{
    this->font_manager = std::move(font_manager);
    this->loading_screen = std::move(loading_screen);
    this->triangle_example = std::move(triangle_example);
}

RendererModule::~RendererModule() = default;

void RendererModule::init()
{
    font_manager->init();
    loading_screen->init();
    triangle_example->init();
}

void RendererModule::shutdown()
{
    triangle_example->shutdown();
    loading_screen->shutdown();
    font_manager->shutdown();
}

void RendererModule::update()
{
}

} // namespace inexor::renderer
