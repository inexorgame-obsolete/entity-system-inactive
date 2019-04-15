#include "InputProcessors.hpp"

namespace inexor {
namespace input {

	InputProcessors::InputProcessors(
		GlobalKeyProcessorPtr global_key_processor
	)
	{
		this->global_key_processor = global_key_processor;
	}

	InputProcessors::~InputProcessors()
	{
	}

	void InputProcessors::init()
	{
		global_key_processor->init();
	}

}
}
