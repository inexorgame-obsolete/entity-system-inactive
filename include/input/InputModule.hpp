#pragma once

#include "base/LifeCycleComponent.hpp"
#include "input/managers/ClipboardManager.hpp"
#include "input/managers/KeyboardInputManager.hpp"
#include "input/managers/MouseInputManager.hpp"
#include "input/processors/InputProcessors.hpp"

namespace inexor::input {

/// @class InputModule
/// @brief A module for handling input (keyboard, mouse, joystick, gamepad).
class InputModule : public LifeCycleComponent
{
    using KeyboardInputManagerPtr = std::shared_ptr<KeyboardInputManager>;
    using MouseInputManagerPtr = std::shared_ptr<MouseInputManager>;
    using ClipboardManagerPtr = std::shared_ptr<ClipboardManager>;
    using InputProcessorsPtr = std::shared_ptr<InputProcessors>;

    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param keyboard_input_manager The keyboard input manager.
    /// @param mouse_input_manager The mouse input manager.
    /// @param input_processors The input processors.
    InputModule(KeyboardInputManagerPtr keyboard_input_manager, MouseInputManagerPtr mouse_input_manager, ClipboardManagerPtr clipboard_manager, InputProcessorsPtr input_processors);

    /// Destructor.
    ~InputModule();

    /// Updates the input module.
    void update();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The keyboard input manager.
    KeyboardInputManagerPtr keyboard_input_manager;

    /// The mouse input manager.
    MouseInputManagerPtr mouse_input_manager;

    /// The clipboard manager.
    ClipboardManagerPtr clipboard_manager;

    /// The input processors.
    InputProcessorsPtr input_processors;
};

} // namespace inexor::input
