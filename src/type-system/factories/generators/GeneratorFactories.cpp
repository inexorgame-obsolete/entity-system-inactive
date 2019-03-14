#include "GeneratorFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	GeneratorFactories::GeneratorFactories(
		CounterFactoriesPtr counter_factories
	)
	{
		this->counter_factories = counter_factories;
	}

	GeneratorFactories::~GeneratorFactories()
	{
	}

	void GeneratorFactories::init()
	{
		counter_factories->init();
	}

}
}
}
