#include "FloatConstantFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	FloatConstantFactory::FloatConstantFactory(
		FloatConstantEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	FloatConstantFactory::~FloatConstantFactory()
	{
	}

	void FloatConstantFactory::init()
	{
	}

	EntityInstancePtrOpt FloatConstantFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_NAME, "")
			->attribute(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, 0.0f)
			->build();
	}

	EntityInstancePtrOpt FloatConstantFactory::create_instance(const std::string& name, const float& value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_NAME, name)
			->attribute(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, value)
			->build();
	}

}
}
}
