#include "DataFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

DataFactories::DataFactories(ConstantFactoriesPtr constant_factories, ConverterFactoriesPtr converter_factories, StoreFactoriesPtr store_factories)
{
    this->constant_factories = std::move(constant_factories);
    this->converter_factories = std::move(converter_factories);
    this->store_factories = std::move(store_factories);
}

DataFactories::~DataFactories() = default;

void DataFactories::init()
{
    constant_factories->init();
    converter_factories->init();
    store_factories->init();
}

} // namespace inexor::entity_system::type_system
