#include "GeneratorProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	GeneratorProcessors::GeneratorProcessors(
		CounterProcessorsPtr counter_processors
	)
	{
		this->counter_processors = counter_processors;
	}

	GeneratorProcessors::~GeneratorProcessors()
	{
	}

	void GeneratorProcessors::init()
	{
		counter_processors->init();
	}

}
}
