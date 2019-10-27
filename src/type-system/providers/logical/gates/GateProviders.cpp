#include "GateProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

GateProviders::GateProviders(NotEntityTypeProviderPtr not_entity_type_provider, OrEntityTypeProviderPtr or_entity_type_provider, AndEntityTypeProviderPtr and_entity_type_provider, XorEntityTypeProviderPtr xor_entity_type_provider,
                             NorEntityTypeProviderPtr nor_entity_type_provider, NandEntityTypeProviderPtr nand_entity_type_provider)
{
    this->not_entity_type_provider = std::move(not_entity_type_provider);
    this->or_entity_type_provider = std::move(or_entity_type_provider);
    this->and_entity_type_provider = std::move(and_entity_type_provider);
    this->xor_entity_type_provider = std::move(xor_entity_type_provider);
    this->nor_entity_type_provider = std::move(nor_entity_type_provider);
    this->nand_entity_type_provider = std::move(nand_entity_type_provider);
}

GateProviders::~GateProviders() = default;

void GateProviders::init()
{
}

} // namespace inexor::entity_system::type_system
