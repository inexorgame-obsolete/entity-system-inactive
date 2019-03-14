#include "ConstantFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	ConstantFactories::ConstantFactories(
		BoolConstantFactoryPtr bool_constant_factory,
		FloatConstantFactoryPtr float_constant_factory,
		IntConstantFactoryPtr int_constant_factory,
		StringConstantFactoryPtr string_constant_factory
	)
	{
		this->bool_constant_factory = bool_constant_factory;
		this->float_constant_factory = float_constant_factory;
		this->int_constant_factory = int_constant_factory;
		this->string_constant_factory = string_constant_factory;
	}

	ConstantFactories::~ConstantFactories()
	{
	}

	void ConstantFactories::init()
	{
		bool_constant_factory->init();
		float_constant_factory->init();
		int_constant_factory->init();
		string_constant_factory->init();
	}

}
}
}
