#include "ArithmeticProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

ArithmeticProcessors::ArithmeticProcessors(AddIntProcessorPtr add_int_processor, AddFloatProcessorPtr add_float_processor)
    : LifeCycleComponent(add_int_processor, add_float_processor)
{
    this->add_int_processor = std::move(add_int_processor);
    this->add_float_processor = std::move(add_float_processor);
}

ArithmeticProcessors::~ArithmeticProcessors() = default;

std::string ArithmeticProcessors::get_component_name()
{
    return "ArithmeticProcessors";
}

} // namespace inexor::visual_scripting
