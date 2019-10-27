#include "InOutProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

InOutProviders::InOutProviders(ConsoleProvidersPtr console_providers, KeyboardProvidersPtr keyboard_providers, MouseProvidersPtr mouse_providers, LoggerProvidersPtr logger_providers)
{
    this->console_providers = std::move(console_providers);
    this->keyboard_providers = std::move(keyboard_providers);
    this->mouse_providers = std::move(mouse_providers);
    this->logger_providers = std::move(logger_providers);
}

InOutProviders::~InOutProviders() = default;

void InOutProviders::init()
{
    console_providers->init();
    keyboard_providers->init();
    mouse_providers->init();
    logger_providers->init();
}

} // namespace inexor::entity_system::type_system
