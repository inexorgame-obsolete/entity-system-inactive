#include "RandomProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	RandomProcessors::RandomProcessors(
		RandomNextIntProcessorPtr random_next_int_processor,
		RandomNextFloatProcessorPtr random_next_float_processor
	)
	{
		this->random_next_int_processor = random_next_int_processor;
		this->random_next_float_processor = random_next_float_processor;
	}

	RandomProcessors::~RandomProcessors()
	{
	}

	void RandomProcessors::init()
	{
		random_next_int_processor->init();
		random_next_float_processor->init();
	}

}
}
