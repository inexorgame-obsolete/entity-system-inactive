#include "TimerProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	TimerProcessors::TimerProcessors(
		TimerTickProcessorPtr timer_tick_processor
	)
	{
		this->timer_tick_processor = timer_tick_processor;
	}

	TimerProcessors::~TimerProcessors()
	{
	}

	void TimerProcessors::init()
	{
		timer_tick_processor->init();
	}

}
}
