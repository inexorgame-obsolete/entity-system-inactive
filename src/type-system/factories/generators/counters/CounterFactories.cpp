#include "CounterFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	CounterFactories::CounterFactories(
		CounterIntFactoryPtr counter_int_factory,
		CounterFloatFactoryPtr counter_float_factory
	)
	{
		this->counter_int_factory = counter_int_factory;
		this->counter_float_factory = counter_float_factory;
	}

	CounterFactories::~CounterFactories()
	{
	}

	void CounterFactories::init()
	{
		counter_int_factory->init();
		counter_float_factory->init();
	}

}
}
}
