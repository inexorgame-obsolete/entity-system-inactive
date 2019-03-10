// Inexor entity system
// (c)2018 Inexor

#include "IntToFloatFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	IntToFloatFactory::IntToFloatFactory(
		shared_ptr<IntToFloatEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	IntToFloatFactory::~IntToFloatFactory()
	{
	}

	O_ENT_INST IntToFloatFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("int_to_float_input", 0)
			->attribute("int_to_float_value", 0.0f)
			->build();
	}

	O_ENT_INST IntToFloatFactory::create_instance(const string& name, const int& int_value, const float& float_value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("int_to_float_input", int_value)
			->attribute("int_to_float_value", float_value)
			->build();
	}

}
}
}
