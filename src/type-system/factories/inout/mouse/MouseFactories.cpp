#include <type-system/factories/inout/mouse/MouseFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

MouseFactories::MouseFactories(GlobalMouseButtonFactoryPtr global_mouse_button_factory)
    : LifeCycleComponent(global_mouse_button_factory)
{
    this->global_mouse_button_factory = std::move(global_mouse_button_factory);
}

MouseFactories::~MouseFactories() = default;

std::string MouseFactories::get_component_name()
{
    return "MouseFactories";
}

GlobalMouseButtonFactoryPtr MouseFactories::get_global_mouse_button_factory()
{
    return global_mouse_button_factory;
}

} // namespace inexor::entity_system::type_system
