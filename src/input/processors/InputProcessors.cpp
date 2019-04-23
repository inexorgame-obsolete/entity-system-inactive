#include "InputProcessors.hpp"

namespace inexor {
namespace input {

	InputProcessors::InputProcessors(
		GlobalKeyProcessorPtr global_key_processor,
		GlobalMouseButtonProcessorPtr global_mouse_button_processor
	)
	{
		this->global_key_processor = global_key_processor;
		this->global_mouse_button_processor = global_mouse_button_processor;
	}

	InputProcessors::~InputProcessors()
	{
	}

	void InputProcessors::init()
	{
		global_key_processor->init();
		global_mouse_button_processor->init();
	}

}
}
