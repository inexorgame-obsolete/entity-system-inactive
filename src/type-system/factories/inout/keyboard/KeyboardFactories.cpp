#include <type-system/factories/inout/keyboard/KeyboardFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

KeyboardFactories::KeyboardFactories(GlobalKeyFactoryPtr global_key_factory)
    : LifeCycleComponent(global_key_factory)
{
    this->global_key_factory = std::move(global_key_factory);
}

KeyboardFactories::~KeyboardFactories() = default;

std::string KeyboardFactories::get_component_name()
{
    return "KeyboardFactories";
}

GlobalKeyFactoryPtr KeyboardFactories::get_global_key_factory()
{
    return global_key_factory;
}

} // namespace inexor::entity_system::type_system
