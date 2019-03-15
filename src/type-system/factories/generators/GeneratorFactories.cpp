#include "GeneratorFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	GeneratorFactories::GeneratorFactories(
		CounterFactoriesPtr counter_factories,
		TimerFactoriesPtr timer_factories,
		RandomFactoriesPtr random_factories
	)
	{
		this->counter_factories = counter_factories;
		this->timer_factories = timer_factories;
		this->random_factories = random_factories;
	}

	GeneratorFactories::~GeneratorFactories()
	{
	}

	void GeneratorFactories::init()
	{
		counter_factories->init();
		timer_factories->init();
		random_factories->init();
	}

}
}
}
