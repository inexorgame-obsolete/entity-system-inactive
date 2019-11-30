#include "TypeSystemModule.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TypeSystemModule::TypeSystemModule(TypeSystemInitializerPtr type_system_initializer, TypeSystemFactoriesPtr type_system_factories)
    : LifeCycleComponent(type_system_initializer, type_system_factories)
{
    this->type_system_initializer = std::move(type_system_initializer);
    this->type_system_factories = std::move(type_system_factories);
}

TypeSystemModule::~TypeSystemModule() = default;

std::string TypeSystemModule::get_component_name()
{
    return "TypeSystemModule";
}

} // namespace inexor::entity_system::type_system
