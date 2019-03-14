#include "CounterProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	CounterProcessors::CounterProcessors(
		CounterIntProcessorPtr counter_int_processor,
		CounterFloatProcessorPtr counter_float_processor
	)
	{
		this->counter_int_processor = counter_int_processor;
		this->counter_float_processor = counter_float_processor;
	}

	CounterProcessors::~CounterProcessors()
	{
	}

	void CounterProcessors::init()
	{
		counter_int_processor->init();
		counter_float_processor->init();
	}

}
}
