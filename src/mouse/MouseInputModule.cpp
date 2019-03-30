#include "MouseInputModule.hpp"

namespace inexor {
namespace input {
namespace mouse {

	MouseInputModule::MouseInputModule(
	MouseInputManagerPtr mouse_input_manager
	)
	{
		this->mouse_input_manager = mouse_input_manager;
	}

	MouseInputModule::~MouseInputModule()
	{
	}

	void MouseInputModule::init()
	{
		mouse_input_manager->init();
	}

}
}
}
