#include "KeyboardInputModule.hpp"

namespace inexor {
namespace input {
namespace keyboard {

	KeyboardInputModule::KeyboardInputModule(
		KeyboardInputManagerPtr keyboard_input_manager
	)
	{
		this->keyboard_input_manager = keyboard_input_manager;
	}

	KeyboardInputModule::~KeyboardInputModule()
	{
	}

	void KeyboardInputModule::init()
	{
		keyboard_input_manager->init();
	}

}
}
}
