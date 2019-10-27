#include "StoreFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

StoreFactories::StoreFactories(FloatStoreFactoryPtr float_store_factory, IntStoreFactoryPtr int_store_factory, StringStoreFactoryPtr string_store_factory)
{
    this->float_store_factory = std::move(float_store_factory);
    this->int_store_factory = std::move(int_store_factory);
    this->string_store_factory = std::move(string_store_factory);
}

StoreFactories::~StoreFactories() = default;

void StoreFactories::init()
{
    float_store_factory->init();
    int_store_factory->init();
    string_store_factory->init();
}

} // namespace inexor::entity_system::type_system
