#include "TimerProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TimerProviders::TimerProviders(
		TimerTickEntityTypeProviderPtr timer_tick_entity_type_provider
	)
	{
		this->timer_tick_entity_type_provider = timer_tick_entity_type_provider;
	}

	TimerProviders::~TimerProviders()
	{
	}

	void TimerProviders::init()
	{
	}

}
}
}
