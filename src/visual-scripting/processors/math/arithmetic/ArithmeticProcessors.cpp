#include "ArithmeticProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	ArithmeticProcessors::ArithmeticProcessors(
		AddIntProcessorPtr add_int_processor,
		AddFloatProcessorPtr add_float_processor
	)
	{
		this->add_int_processor = add_int_processor;
		this->add_float_processor = add_float_processor;
	}

	ArithmeticProcessors::~ArithmeticProcessors()
	{
	}

	void ArithmeticProcessors::init()
	{
		add_int_processor->init();
		add_float_processor->init();
	}

}
}
