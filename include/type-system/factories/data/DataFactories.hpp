#pragma once

#include <boost/di.hpp>

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/data/constants/ConstantFactories.hpp"
#include "type-system/factories/data/converters/ConverterFactories.hpp"
#include "type-system/factories/data/stores/StoreFactories.hpp"

namespace inexor::entity_system::type_system {

using ConstantFactoriesPtr = std::shared_ptr<ConstantFactories>;
using ConverterFactoriesPtr = std::shared_ptr<ConverterFactories>;
using StoreFactoriesPtr = std::shared_ptr<StoreFactories>;

/// @class DataFactories
/// @brief The factories for constants and stores.
class DataFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the factories for constants and stores.
    /// @param constant_factories The factories for constants.
    /// @param converter_factories The factories for converters.
    /// @param store_factories The factories for stores.
    DataFactories(ConstantFactoriesPtr constant_factories, ConverterFactoriesPtr converter_factories, StoreFactoriesPtr store_factories);

    // This is necessary for constructor length greater than 10
    using boost_di_inject__ = boost::di::inject<ConstantFactoriesPtr, ConverterFactoriesPtr, StoreFactoriesPtr>;

    /// Destructor.
    ~DataFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The factories for constants.
    ConstantFactoriesPtr constant_factories;

    /// The factories for converters.
    ConverterFactoriesPtr converter_factories;

    /// The factories for stores.
    StoreFactoriesPtr store_factories;
};

} // namespace inexor::entity_system::type_system
