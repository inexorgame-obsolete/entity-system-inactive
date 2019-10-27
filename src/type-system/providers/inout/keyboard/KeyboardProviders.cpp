#include "KeyboardProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

KeyboardProviders::KeyboardProviders(GlobalKeyEntityTypeProviderPtr global_key_entity_type_provider)
{
    this->global_key_entity_type_provider = std::move(global_key_entity_type_provider);
}

KeyboardProviders::~KeyboardProviders() = default;

void KeyboardProviders::init()
{
}

} // namespace inexor::entity_system::type_system
