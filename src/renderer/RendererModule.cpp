#include "RendererModule.hpp"

// Statically import the magnum plugins
// This is the only place to do this!
#include "renderer/plugins/MagnumPlugins.cpp"

#include <GLFW/glfw3.h>

#include <utility>

namespace inexor::renderer {

RendererModule::RendererModule(FontManagerPtr font_manager, LoadingScreenPtr loading_screen, TriangleExamplePtr triangle_example)
    : LifeCycleComponent(font_manager, loading_screen, triangle_example)
{
    this->font_manager = std::move(font_manager);
    this->loading_screen = std::move(loading_screen);
    this->triangle_example = std::move(triangle_example);
}

RendererModule::~RendererModule() = default;

std::string RendererModule::get_component_name()
{
    return "RendererModule";
}

void RendererModule::update()
{
}

} // namespace inexor::renderer
