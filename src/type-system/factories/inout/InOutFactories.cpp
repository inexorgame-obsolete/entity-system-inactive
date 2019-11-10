#include "InOutFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

InOutFactories::InOutFactories(KeyboardFactoriesPtr keyboard_factories, MouseFactoriesPtr mouse_factories, LoggerFactoriesPtr logger_factories)
    : LifeCycleComponent(keyboard_factories, mouse_factories, logger_factories)
{
    this->keyboard_factories = std::move(keyboard_factories);
    this->mouse_factories = std::move(mouse_factories);
    this->logger_factories = std::move(logger_factories);
}

InOutFactories::~InOutFactories() = default;

std::string InOutFactories::get_component_name()
{
    return "InOutFactories";
}

KeyboardFactoriesPtr InOutFactories::get_keyboard_factories()
{
    return keyboard_factories;
}

MouseFactoriesPtr InOutFactories::get_mouse_factories()
{
    return mouse_factories;
}

} // namespace inexor::entity_system::type_system
