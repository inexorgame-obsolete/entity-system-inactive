#include "TypeSystemFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TypeSystemFactories::TypeSystemFactories(
		DataFactoriesPtr data_factories,
		InOutFactoriesPtr in_out_factories,
		GeneratorFactoriesPtr generator_factories,
		LogicalFactoriesPtr logical_factories,
		MathFactoriesPtr math_factories
	)
	{
		this->data_factories = data_factories;
		this->in_out_factories = in_out_factories;
		this->generator_factories = generator_factories;
		this->logical_factories = logical_factories;
		this->math_factories = math_factories;
	}

	TypeSystemFactories::~TypeSystemFactories()
	{
	}

	void TypeSystemFactories::init()
	{
		data_factories->init();
		in_out_factories->init();
		generator_factories->init();
		logical_factories->init();
		math_factories->init();
	}

	InOutFactoriesPtr TypeSystemFactories::get_in_out_factories()
	{
		return in_out_factories;
	}

}
}
}
