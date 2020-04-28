#include <visual-scripting/processors/data/converters/ConverterProcessors.hpp>

#include <utility>

namespace inexor::visual_scripting {

ConverterProcessors::ConverterProcessors(IntToFloatProcessorPtr int_to_float_processor, IntToStringProcessorPtr int_to_string_processor)
    : LifeCycleComponent(int_to_float_processor, int_to_string_processor)
{
    this->int_to_float_processor = std::move(int_to_float_processor);
    this->int_to_string_processor = std::move(int_to_string_processor);
}

ConverterProcessors::~ConverterProcessors() = default;

std::string ConverterProcessors::get_component_name()
{
    return "ConverterProcessors";
}

} // namespace inexor::visual_scripting
