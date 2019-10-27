#include "InputModule.hpp"

#include <utility>

namespace inexor::input {

InputModule::InputModule(KeyboardInputManagerPtr keyboard_input_manager, MouseInputManagerPtr mouse_input_manager, ClipboardManagerPtr clipboard_manager, InputProcessorsPtr input_processors)
{
    this->keyboard_input_manager = std::move(keyboard_input_manager);
    this->mouse_input_manager = std::move(mouse_input_manager);
    this->clipboard_manager = std::move(clipboard_manager);
    this->input_processors = std::move(input_processors);
}

InputModule::~InputModule() = default;

void InputModule::init()
{
    keyboard_input_manager->init();
    mouse_input_manager->init();
    clipboard_manager->init();
    input_processors->init();
}

void InputModule::shutdown()
{
    // input_processors->shutdown();
    clipboard_manager->shutdown();
    mouse_input_manager->shutdown();
    keyboard_input_manager->shutdown();
}

void InputModule::update()
{
    clipboard_manager->update();
}

} // namespace inexor::input
