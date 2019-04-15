#include "InputModule.hpp"

namespace inexor {
namespace input {

	InputModule::InputModule(
		KeyboardInputManagerPtr keyboard_input_manager,
		MouseInputManagerPtr mouse_input_manager,
		InputProcessorsPtr input_processors
	)
	{
		this->keyboard_input_manager = keyboard_input_manager;
		this->mouse_input_manager = mouse_input_manager;
		this->input_processors = input_processors;
	}

	InputModule::~InputModule()
	{
	}

	void InputModule::init()
	{
		keyboard_input_manager->init();
		mouse_input_manager->init();
		input_processors->init();
	}

	void InputModule::shutdown()
	{
		keyboard_input_manager->shutdown();
		mouse_input_manager->shutdown();
		// input_processors->shutdown();
	}

}
}
