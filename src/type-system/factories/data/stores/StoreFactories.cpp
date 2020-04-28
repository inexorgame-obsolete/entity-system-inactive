#include <type-system/factories/data/stores/StoreFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

StoreFactories::StoreFactories(FloatStoreFactoryPtr float_store_factory, IntStoreFactoryPtr int_store_factory, StringStoreFactoryPtr string_store_factory)
    : LifeCycleComponent(float_store_factory, int_store_factory, string_store_factory)
{
    this->float_store_factory = std::move(float_store_factory);
    this->int_store_factory = std::move(int_store_factory);
    this->string_store_factory = std::move(string_store_factory);
}

StoreFactories::~StoreFactories() = default;

std::string StoreFactories::get_component_name()
{
    return "StoreFactories";
}

} // namespace inexor::entity_system::type_system
