#include <visual-scripting/processors/generators/counters/CounterProcessors.hpp>

#include <utility>

namespace inexor::visual_scripting {

CounterProcessors::CounterProcessors(CounterIntProcessorPtr counter_int_processor, CounterFloatProcessorPtr counter_float_processor)
    : LifeCycleComponent(counter_int_processor, counter_float_processor)
{
    this->counter_int_processor = std::move(counter_int_processor);
    this->counter_float_processor = std::move(counter_float_processor);
}

CounterProcessors::~CounterProcessors() = default;

std::string CounterProcessors::get_component_name()
{
    return "CounterProcessors";
}

} // namespace inexor::visual_scripting
