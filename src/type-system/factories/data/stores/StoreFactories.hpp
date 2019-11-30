#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/data/stores/FloatStoreFactory.hpp"
#include "type-system/factories/data/stores/IntStoreFactory.hpp"
#include "type-system/factories/data/stores/StringStoreFactory.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using FloatStoreFactoryPtr = std::shared_ptr<FloatStoreFactory>;
using IntStoreFactoryPtr = std::shared_ptr<IntStoreFactory>;
using StringStoreFactoryPtr = std::shared_ptr<StringStoreFactory>;

/// @class StoreFactories
/// @brief The store factories.
class StoreFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the store factories.
    /// @param float_store_factory Factory for creating entity instances of type FLOAT_STORE.
    /// @param int_store_factory Factory for creating entity instances of type INT_STORE.
    /// @param string_store_factory Factory for creating entity instances of type STRING_STORE.
    StoreFactories(FloatStoreFactoryPtr float_store_factory, IntStoreFactoryPtr int_store_factory, StringStoreFactoryPtr string_store_factory);

    /// Destructor.
    ~StoreFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Factory for creating entity instances of type FLOAT_STORE.
    FloatStoreFactoryPtr float_store_factory;

    /// Factory for creating entity instances of type INT_STORE.
    IntStoreFactoryPtr int_store_factory;

    /// Factory for creating entity instances of type STRING_STORE.
    StringStoreFactoryPtr string_store_factory;
};

} // namespace inexor::entity_system::type_system
