#include "StoreProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

StoreProviders::StoreProviders(FloatStoreEntityTypeProviderPtr float_store_entity_type_provider, IntStoreEntityTypeProviderPtr int_store_entity_type_provider, StringStoreEntityTypeProviderPtr string_store_entity_type_provider)
{
    this->float_store_entity_type_provider = std::move(float_store_entity_type_provider);
    this->int_store_entity_type_provider = std::move(int_store_entity_type_provider);
    this->string_store_entity_type_provider = std::move(string_store_entity_type_provider);
}

StoreProviders::~StoreProviders() = default;

void StoreProviders::init()
{
}

} // namespace inexor::entity_system::type_system
