#include "ArithmeticFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	ArithmeticFactories::ArithmeticFactories(
		AddIntFactoryPtr add_int_factory,
		AddFloatFactoryPtr add_float_factory
	)
	{
		this->add_int_factory = add_int_factory;
		this->add_float_factory = add_float_factory;
	}

	ArithmeticFactories::~ArithmeticFactories()
	{
	}

	void ArithmeticFactories::init()
	{
		add_int_factory->init();
		add_float_factory->init();
	}

}
}
}
