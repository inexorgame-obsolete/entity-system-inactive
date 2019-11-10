#include "ConverterProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

ConverterProcessors::ConverterProcessors(IntToFloatProcessorPtr int_to_float_processor, IntToStringProcessorPtr int_to_string_processor)
{
    this->int_to_float_processor = std::move(int_to_float_processor);
    this->int_to_string_processor = std::move(int_to_string_processor);
}

ConverterProcessors::~ConverterProcessors() = default;

void ConverterProcessors::init()
{
    int_to_float_processor->init();
    int_to_string_processor->init();
}

void ConverterProcessors::shutdown()
{
    int_to_float_processor->shutdown();
    int_to_string_processor->shutdown();
}

} // namespace inexor::visual_scripting
