#include "ComparisonProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

ComparisonProcessors::ComparisonProcessors(EqualsBoolProcessorPtr equals_bool_processor, EqualsIntProcessorPtr equals_int_processor, EqualsStringProcessorPtr equals_string_processor, GreaterThanIntProcessorPtr greater_than_int_processor,
                                           GreaterThanFloatProcessorPtr greater_than_float_processor, LowerThanIntProcessorPtr lower_than_int_processor, LowerThanFloatProcessorPtr lower_than_float_processor,
                                           InRangeIntProcessorPtr in_range_int_processor, InRangeFloatProcessorPtr in_range_float_processor)
{
    this->equals_bool_processor = std::move(equals_bool_processor);
    this->equals_int_processor = std::move(equals_int_processor);
    this->equals_string_processor = std::move(equals_string_processor);
    this->greater_than_int_processor = std::move(greater_than_int_processor);
    this->greater_than_float_processor = std::move(greater_than_float_processor);
    this->lower_than_int_processor = std::move(lower_than_int_processor);
    this->lower_than_float_processor = std::move(lower_than_float_processor);
    this->in_range_int_processor = std::move(in_range_int_processor);
    this->in_range_float_processor = std::move(in_range_float_processor);
}

ComparisonProcessors::~ComparisonProcessors() = default;

void ComparisonProcessors::init()
{
    equals_bool_processor->init();
    equals_int_processor->init();
    equals_string_processor->init();
    greater_than_int_processor->init();
    greater_than_float_processor->init();
    lower_than_int_processor->init();
    lower_than_float_processor->init();
    in_range_int_processor->init();
    in_range_float_processor->init();
}

} // namespace inexor::visual_scripting
