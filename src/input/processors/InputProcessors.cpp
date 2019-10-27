#include "InputProcessors.hpp"

#include <utility>

namespace inexor::input {

InputProcessors::InputProcessors(GlobalKeyProcessorPtr global_key_processor, GlobalMouseButtonProcessorPtr global_mouse_button_processor)
{
    this->global_key_processor = std::move(global_key_processor);
    this->global_mouse_button_processor = std::move(global_mouse_button_processor);
}

InputProcessors::~InputProcessors() = default;

void InputProcessors::init()
{
    global_key_processor->init();
    global_mouse_button_processor->init();
}

} // namespace inexor::input
