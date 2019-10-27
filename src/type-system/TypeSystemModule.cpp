#include "TypeSystemModule.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TypeSystemModule::TypeSystemModule(TypeSystemProvidersPtr type_system_providers, TypeSystemFactoriesPtr type_system_factories)
{
    this->type_system_providers = std::move(type_system_providers);
    this->type_system_factories = std::move(type_system_factories);
}

TypeSystemModule::~TypeSystemModule()
{
}

void TypeSystemModule::init()
{
    type_system_providers->init();
    type_system_factories->init();
}

} // namespace inexor::entity_system::type_system
