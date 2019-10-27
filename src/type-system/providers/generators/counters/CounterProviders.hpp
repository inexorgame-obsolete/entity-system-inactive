#pragma once

#include "type-system/providers/generators/counters/CounterFloatEntityTypeProvider.hpp"
#include "type-system/providers/generators/counters/CounterIntEntityTypeProvider.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using CounterIntEntityTypeProviderPtr = std::shared_ptr<CounterIntEntityTypeProvider>;
using CounterFloatEntityTypeProviderPtr = std::shared_ptr<CounterFloatEntityTypeProvider>;

/// @class CounterProviders
/// @brief The entity type providers for counters.
class CounterProviders
{
    public:
    /// @brief Constructs the entity type providers for counters.
    /// @note The dependencies of this class will be injected automatically.
    /// @param counter_int_entity_type_provider Provides the entity type COUNTER_INT.
    /// @param counter_float_entity_type_provider Provides the entity type COUNTER_FLOAT.
    CounterProviders(CounterIntEntityTypeProviderPtr counter_int_entity_type_provider, CounterFloatEntityTypeProviderPtr counter_float_entity_type_provider);

    /// Destructor.
    ~CounterProviders();

    /// Initializes the providers for logical operations.
    void init();

    private:
    /// Provides the entity type COUNTER_INT.
    CounterIntEntityTypeProviderPtr counter_int_entity_type_provider;

    /// Provides the entity type COUNTER_FLOAT.
    CounterFloatEntityTypeProviderPtr counter_float_entity_type_provider;
};

} // namespace inexor::entity_system::type_system
