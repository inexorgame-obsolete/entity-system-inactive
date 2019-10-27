#pragma once

#include "type-system/factories/generators/counters/CounterFloatFactory.hpp"
#include "type-system/factories/generators/counters/CounterIntFactory.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using CounterIntFactoryPtr = std::shared_ptr<CounterIntFactory>;
using CounterFloatFactoryPtr = std::shared_ptr<CounterFloatFactory>;

/// @class CounterFactories
/// @brief Provides the factories for counters.
class CounterFactories
{
    public:
    /// @brief Constructs the factories for counters.
    /// @note The dependencies of this class will be injected automatically.
    /// @param counter_int_factory Factory for creating entity instances of type COUNTER_INT.
    /// @param counter_float_factory Factory for creating entity instances of type COUNTER_FLOAT.
    CounterFactories(CounterIntFactoryPtr counter_int_factory, CounterFloatFactoryPtr counter_float_factory);

    /// Destructor.
    ~CounterFactories();

    /// Initializes the factories for counters.
    void init();

    private:
    /// Factory for creating entity instances of type COUNTER_INT.
    CounterIntFactoryPtr counter_int_factory;

    /// Factory for creating entity instances of type COUNTER_FLOAT.
    CounterFloatFactoryPtr counter_float_factory;
};

} // namespace inexor::entity_system::type_system
