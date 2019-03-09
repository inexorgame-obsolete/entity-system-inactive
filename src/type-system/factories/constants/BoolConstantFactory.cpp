#include "BoolConstantFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	BoolConstantFactory::BoolConstantFactory(
		shared_ptr<BoolConstantEntityTypeProvider> entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	BoolConstantFactory::~BoolConstantFactory()
	{
	}

	EntityInstancePtrOpt BoolConstantFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("bool_constant_name", "")
			->attribute("bool_constant_value", false)
			->build();
	}

	EntityInstancePtrOpt BoolConstantFactory::create_instance(const string& name, const bool& value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("bool_constant_name", name)
			->attribute("bool_constant_value", value)
			->build();
	}

}
}
}
