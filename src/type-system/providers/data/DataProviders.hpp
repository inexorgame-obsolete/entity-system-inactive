#pragma once

#include "type-system/providers/data/constants/ConstantProviders.hpp"
#include "type-system/providers/data/converters/ConverterProviders.hpp"
#include "type-system/providers/data/stores/StoreProviders.hpp"

namespace inexor::entity_system::type_system {

using ConstantProvidersPtr = std::shared_ptr<ConstantProviders>;
using ConverterProvidersPtr = std::shared_ptr<ConverterProviders>;
using StoreProvidersPtr = std::shared_ptr<StoreProviders>;

/// @class DataProviders
/// @brief The providers of the type system.
class DataProviders
{
    public:
    /// @brief Constructs the providers of the type system.
    /// @note The dependencies of this class will be injected automatically.
    /// @param constant_providers The providers for constants.
    /// @param converter_providers The providers for converters.
    /// @param store_providers The providers for stores.
    DataProviders(ConstantProvidersPtr constant_providers, ConverterProvidersPtr converter_providers, StoreProvidersPtr store_providers);

    /// Destructor.
    ~DataProviders();

    /// Initializes the providers of the type system.
    void init();

    private:
    /// The providers for constants.
    ConstantProvidersPtr constant_providers;

    /// The providers for converters.
    ConverterProvidersPtr converter_providers;

    /// The providers for stores.
    StoreProvidersPtr store_providers;
};

} // namespace inexor::entity_system::type_system
