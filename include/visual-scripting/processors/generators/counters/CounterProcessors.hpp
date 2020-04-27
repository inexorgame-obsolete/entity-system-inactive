#pragma once

#include "visual-scripting/processors/generators/counters/CounterFloatProcessor.hpp"
#include "visual-scripting/processors/generators/counters/CounterIntProcessor.hpp"

namespace inexor::visual_scripting {

using CounterIntProcessorPtr = std::shared_ptr<CounterIntProcessor>;
using CounterFloatProcessorPtr = std::shared_ptr<CounterFloatProcessor>;

/// @class CounterProcessors
/// @brief Provides processors for time based counters.
class CounterProcessors : public LifeCycleComponent
{
    public:
    /// @brief Constructs the processors for time based counters.
    /// @note The dependencies of this class will be injected automatically.
    /// @param counter_int_processor Processor for the entity type COUNTER_INT.
    /// @param counter_float_processor Processor for the entity type COUNTER_FLOAT.
    CounterProcessors(CounterIntProcessorPtr counter_int_processor, CounterFloatProcessorPtr counter_float_processor);

    /// Destructor.
    ~CounterProcessors();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Processor for the entity type COUNTER_INT.
    CounterIntProcessorPtr counter_int_processor;

    /// Processor for the entity type COUNTER_FLOAT.
    CounterFloatProcessorPtr counter_float_processor;
};

} // namespace inexor::visual_scripting
