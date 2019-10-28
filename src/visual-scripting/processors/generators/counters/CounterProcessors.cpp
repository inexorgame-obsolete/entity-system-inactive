#include "CounterProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

CounterProcessors::CounterProcessors(CounterIntProcessorPtr counter_int_processor, CounterFloatProcessorPtr counter_float_processor)
{
    this->counter_int_processor = std::move(counter_int_processor);
    this->counter_float_processor = std::move(counter_float_processor);
}

CounterProcessors::~CounterProcessors() = default;

void CounterProcessors::init()
{
    counter_int_processor->init();
    counter_float_processor->init();
}

void CounterProcessors::shutdown()
{
    counter_int_processor->shutdown();
    counter_float_processor->shutdown();
}

} // namespace inexor::visual_scripting
