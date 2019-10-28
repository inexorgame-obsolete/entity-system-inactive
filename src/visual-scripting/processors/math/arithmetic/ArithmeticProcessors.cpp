#include "ArithmeticProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

ArithmeticProcessors::ArithmeticProcessors(AddIntProcessorPtr add_int_processor, AddFloatProcessorPtr add_float_processor)
{
    this->add_int_processor = std::move(add_int_processor);
    this->add_float_processor = std::move(add_float_processor);
}

ArithmeticProcessors::~ArithmeticProcessors() = default;

void ArithmeticProcessors::init()
{
    add_int_processor->init();
    add_float_processor->init();
}

} // namespace inexor::visual_scripting
