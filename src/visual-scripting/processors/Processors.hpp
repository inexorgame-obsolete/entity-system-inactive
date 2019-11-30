#pragma once

#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"
#include "visual-scripting/processors/data/DataProcessors.hpp"
#include "visual-scripting/processors/generators/GeneratorProcessors.hpp"
#include "visual-scripting/processors/inout/InOutProcessors.hpp"
#include "visual-scripting/processors/logical/LogicalProcessors.hpp"
#include "visual-scripting/processors/math/MathProcessors.hpp"

namespace inexor::visual_scripting {

using ProcessorRegistryPtr = std::shared_ptr<ProcessorRegistry>;
using DataProcessorsPtr = std::shared_ptr<DataProcessors>;
using GeneratorProcessorsPtr = std::shared_ptr<GeneratorProcessors>;
using InOutProcessorsPtr = std::shared_ptr<InOutProcessors>;
using LogicalProcessorsPtr = std::shared_ptr<LogicalProcessors>;
using MathProcessorsPtr = std::shared_ptr<MathProcessors>;

/// @class Processors
/// @brief Provides the processors.
class Processors : public LifeCycleComponent
{
    public:
    /// @brief Constructs the processors.
    /// @note The dependencies of this class will be injected automatically.
    /// @param processor_registry The registry for processors.
    /// @param data_processors The processors for data types and values.
    /// @param generator_processors The processors for generators like counters and timers.
    /// @param inout_processors The processors for input and output.
    /// @param logical_processors The processors for logical operations.
    /// @param math_processors The processors for mathematical operations.
    Processors(ProcessorRegistryPtr processor_registry, DataProcessorsPtr data_processors, GeneratorProcessorsPtr generator_processors, InOutProcessorsPtr inout_processors, LogicalProcessorsPtr logical_processors, MathProcessorsPtr math_processors);

    /// Destructor.
    ~Processors();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The registry for processors.
    ProcessorRegistryPtr processor_registry;

    /// The processors for data types and values.
    DataProcessorsPtr data_processors;

    /// The processors for generators like counters and timers.
    GeneratorProcessorsPtr generator_processors;

    /// The processors for input and output.
    InOutProcessorsPtr inout_processors;

    /// The processors for logical operations.
    LogicalProcessorsPtr logical_processors;

    /// The processors for mathematical operations.
    MathProcessorsPtr math_processors;
};

} // namespace inexor::visual_scripting
