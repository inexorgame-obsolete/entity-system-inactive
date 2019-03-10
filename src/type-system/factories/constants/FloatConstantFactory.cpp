#include "FloatConstantFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	FloatConstantFactory::FloatConstantFactory(
		shared_ptr<FloatConstantEntityTypeProvider> entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	FloatConstantFactory::~FloatConstantFactory()
	{
	}

	EntityInstancePtrOpt FloatConstantFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("float_constant_name", "")
			->attribute("float_constant_value", 0.0f)
			->build();
	}

	EntityInstancePtrOpt FloatConstantFactory::create_instance(const string& name, const float& value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("float_constant_name", name)
			->attribute("float_constant_value", value)
			->build();
	}

}
}
}
