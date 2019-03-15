#include "GeneratorProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	GeneratorProcessors::GeneratorProcessors(
		CounterProcessorsPtr counter_processors,
		TimerProcessorsPtr timer_processors,
		RandomProcessorsPtr random_processors
	)
	{
		this->counter_processors = counter_processors;
		this->timer_processors = timer_processors;
		this->random_processors = random_processors;
	}

	GeneratorProcessors::~GeneratorProcessors()
	{
	}

	void GeneratorProcessors::init()
	{
		counter_processors->init();
		timer_processors->init();
		random_processors->init();
	}

}
}
