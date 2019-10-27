#pragma once

#include "type-system/factories/data/constants/ConstantFactories.hpp"
#include "type-system/factories/data/converters/ConverterFactories.hpp"
#include "type-system/factories/data/stores/StoreFactories.hpp"

namespace inexor::entity_system::type_system {

using ConstantFactoriesPtr = std::shared_ptr<ConstantFactories>;
using ConverterFactoriesPtr = std::shared_ptr<ConverterFactories>;
using StoreFactoriesPtr = std::shared_ptr<StoreFactories>;

/// @class DataFactories
/// @brief The factories for constants and stores.
class DataFactories
{
    public:
    /// @brief Constructs the factories for constants and stores.
    /// @note The dependencies of this class will be injected automatically.
    /// @param constant_factories The factories for constants.
    /// @param converter_factories The factories for converters.
    /// @param store_factories The factories for stores.
    DataFactories(ConstantFactoriesPtr constant_factories, ConverterFactoriesPtr converter_factories, StoreFactoriesPtr store_factories);

    /// Destructor.
    ~DataFactories();

    /// Initializes the factories for constants and stores.
    void init();

    private:
    /// The factories for constants.
    ConstantFactoriesPtr constant_factories;

    /// The factories for converters.
    ConverterFactoriesPtr converter_factories;

    /// The factories for stores.
    StoreFactoriesPtr store_factories;
};

} // namespace inexor::entity_system::type_system
