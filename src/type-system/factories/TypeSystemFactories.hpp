#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/data/DataFactories.hpp"
#include "type-system/factories/generators/GeneratorFactories.hpp"
#include "type-system/factories/inout/InOutFactories.hpp"
#include "type-system/factories/logical/LogicalFactories.hpp"
#include "type-system/factories/math/MathFactories.hpp"

namespace inexor::entity_system::type_system {

using DataFactoriesPtr = std::shared_ptr<DataFactories>;
using InOutFactoriesPtr = std::shared_ptr<InOutFactories>;
using GeneratorFactoriesPtr = std::shared_ptr<GeneratorFactories>;
using LogicalFactoriesPtr = std::shared_ptr<LogicalFactories>;
using MathFactoriesPtr = std::shared_ptr<MathFactories>;

/// @class TypeSystemFactories
/// @brief The factories of the type system.
class TypeSystemFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the factories of the type system.
    /// @note The dependencies of this class will be injected automatically.
    /// @param data_factories The factories for data objects like constants and stores.
    /// @param in_out_factories The factories for input and output like console and loggers.
    /// @param generator_factories The factories for generators like counters and timers.
    /// @param logical_factories The factories for the logical operations like comparisons and gates.
    /// @param math_factories The factories for mathematical operations like arithmetic and trigonometric operations.
    TypeSystemFactories(DataFactoriesPtr data_factories, InOutFactoriesPtr in_out_factories, GeneratorFactoriesPtr generator_factories, LogicalFactoriesPtr logical_factories, MathFactoriesPtr math_factories);

    /// Destructor.
    ~TypeSystemFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Returns the factories for input and output like console and loggers.
    InOutFactoriesPtr get_in_out_factories();

    private:
    /// The factories for data objects like constants and stores.
    DataFactoriesPtr data_factories;

    /// The factories for input and output like console and loggers.
    InOutFactoriesPtr in_out_factories;

    /// The factories for generators like counters and timers.
    GeneratorFactoriesPtr generator_factories;

    /// The factories for the logical operations like comparisons and gates.
    LogicalFactoriesPtr logical_factories;

    /// The factories for mathematical operations like arithmetic and trigonometric operations.
    MathFactoriesPtr math_factories;
};

} // namespace inexor::entity_system::type_system
