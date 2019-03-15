#include "RandomFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	RandomFactories::RandomFactories(
		RandomNextIntFactoryPtr random_next_int_factory,
		RandomNextFloatFactoryPtr random_next_float_factory
	)
	{
		this->random_next_int_factory = random_next_int_factory;
		this->random_next_float_factory = random_next_float_factory;
	}

	RandomFactories::~RandomFactories()
	{
	}

	void RandomFactories::init()
	{
		random_next_int_factory->init();
		random_next_float_factory->init();
	}

}
}
}
