#include "MouseFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

MouseFactories::MouseFactories(GlobalMouseButtonFactoryPtr global_mouse_button_factory)
{
    this->global_mouse_button_factory = std::move(global_mouse_button_factory);
}

MouseFactories::~MouseFactories() = default;

void MouseFactories::init()
{
    global_mouse_button_factory->init();
}

GlobalMouseButtonFactoryPtr MouseFactories::get_global_mouse_button_factory()
{
    return global_mouse_button_factory;
}

} // namespace inexor::entity_system::type_system
