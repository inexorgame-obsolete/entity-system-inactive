#include "InputModule.hpp"

#include <utility>

namespace inexor::input {

InputModule::InputModule(KeyboardInputManagerPtr keyboard_input_manager, MouseInputManagerPtr mouse_input_manager, ClipboardManagerPtr clipboard_manager, InputProcessorsPtr input_processors)
    : LifeCycleComponent(keyboard_input_manager, mouse_input_manager, clipboard_manager, input_processors)
{
    this->keyboard_input_manager = std::move(keyboard_input_manager);
    this->mouse_input_manager = std::move(mouse_input_manager);
    this->clipboard_manager = std::move(clipboard_manager);
    this->input_processors = std::move(input_processors);
}

InputModule::~InputModule() = default;

void InputModule::update()
{
    clipboard_manager->update();
}

std::string InputModule::get_component_name()
{
    return "InputModule";
}

} // namespace inexor::input
