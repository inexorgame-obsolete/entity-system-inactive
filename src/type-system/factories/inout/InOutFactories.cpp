#include "InOutFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

InOutFactories::InOutFactories(KeyboardFactoriesPtr keyboard_factories, MouseFactoriesPtr mouse_factories, LoggerFactoriesPtr logger_factories)
{
    this->keyboard_factories = std::move(keyboard_factories);
    this->mouse_factories = std::move(mouse_factories);
    this->logger_factories = std::move(logger_factories);
}

InOutFactories::~InOutFactories() = default;

void InOutFactories::init()
{
    keyboard_factories->init();
    mouse_factories->init();
    logger_factories->init();
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
