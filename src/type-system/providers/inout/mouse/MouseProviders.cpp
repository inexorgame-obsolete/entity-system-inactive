#include "MouseProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

MouseProviders::MouseProviders(GlobalMouseButtonEntityTypeProviderPtr global_mouse_button_entity_type_provider)
{
    this->global_mouse_button_entity_type_provider = std::move(global_mouse_button_entity_type_provider);
}

MouseProviders::~MouseProviders() = default;

void MouseProviders::init()
{
}

} // namespace inexor::entity_system::type_system
