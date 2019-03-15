#include "TimerFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TimerFactories::TimerFactories(
		TimerTickFactoryPtr timer_tick_factory
	)
	{
		this->timer_tick_factory = timer_tick_factory;
	}

	TimerFactories::~TimerFactories()
	{
	}

	void TimerFactories::init()
	{
		timer_tick_factory->init();
	}

}
}
}
