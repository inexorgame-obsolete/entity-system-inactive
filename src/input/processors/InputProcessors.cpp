#include <input/processors/InputProcessors.hpp>

#include <utility>

namespace inexor::input {

InputProcessors::InputProcessors(GlobalKeyProcessorPtr global_key_processor, GlobalMouseButtonProcessorPtr global_mouse_button_processor)
    : LifeCycleComponent(global_key_processor, global_mouse_button_processor)
{
    this->global_key_processor = std::move(global_key_processor);
    this->global_mouse_button_processor = std::move(global_mouse_button_processor);
}

InputProcessors::~InputProcessors() = default;

std::string InputProcessors::get_component_name()
{
    return "InputProcessors";
}

} // namespace inexor::input
