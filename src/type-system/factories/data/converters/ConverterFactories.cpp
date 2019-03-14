#include "ConverterFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	ConverterFactories::ConverterFactories(
		IntToFloatFactoryPtr int_to_float_factory
	)
	{
		this->int_to_float_factory = int_to_float_factory;
	}

	ConverterFactories::~ConverterFactories()
	{
	}

	void ConverterFactories::init()
	{
		int_to_float_factory->init();
	}

}
}
}
