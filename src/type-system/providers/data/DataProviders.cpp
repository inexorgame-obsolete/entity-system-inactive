#include "DataProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

DataProviders::DataProviders(ConstantProvidersPtr constant_providers, ConverterProvidersPtr converter_providers, StoreProvidersPtr store_providers)
{
    this->constant_providers = std::move(constant_providers);
    this->converter_providers = std::move(converter_providers);
    this->store_providers = std::move(store_providers);
}

DataProviders::~DataProviders() = default;

void DataProviders::init()
{
    constant_providers->init();
    converter_providers->init();
    store_providers->init();
}

} // namespace inexor::entity_system::type_system
