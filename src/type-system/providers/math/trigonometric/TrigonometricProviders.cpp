#include "TrigonometricProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TrigonometricProviders::TrigonometricProviders(SinEntityTypeProviderPtr sin_entity_type_provider, CosEntityTypeProviderPtr cos_entity_type_provider, TanEntityTypeProviderPtr tan_entity_type_provider)
{
    this->sin_entity_type_provider = std::move(sin_entity_type_provider);
    this->cos_entity_type_provider = std::move(cos_entity_type_provider);
    this->tan_entity_type_provider = std::move(tan_entity_type_provider);
}

TrigonometricProviders::~TrigonometricProviders() = default;

void TrigonometricProviders::init()
{
}

} // namespace inexor::entity_system::type_system
