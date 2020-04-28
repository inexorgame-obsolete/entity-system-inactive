#include <type-system/factories/data/DataFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

DataFactories::DataFactories(ConstantFactoriesPtr constant_factories, ConverterFactoriesPtr converter_factories, StoreFactoriesPtr store_factories)
    : LifeCycleComponent(constant_factories, converter_factories, store_factories)
{
    this->constant_factories = std::move(constant_factories);
    this->converter_factories = std::move(converter_factories);
    this->store_factories = std::move(store_factories);
}

DataFactories::~DataFactories() = default;

std::string DataFactories::get_component_name()
{
    return "DataFactories";
}

} // namespace inexor::entity_system::type_system
