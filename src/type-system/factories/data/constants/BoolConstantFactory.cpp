#include "BoolConstantFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	BoolConstantFactory::BoolConstantFactory(
		BoolConstantEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	BoolConstantFactory::~BoolConstantFactory()
	{
	}

	void BoolConstantFactory::init()
	{
	}

	EntityInstancePtrOpt BoolConstantFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(BoolConstantEntityTypeProvider::BOOL_CONSTANT_NAME, "")
			->attribute(BoolConstantEntityTypeProvider::BOOL_CONSTANT_VALUE, false)
			->build();
	}

	EntityInstancePtrOpt BoolConstantFactory::create_instance(const std::string& name, const bool& value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(BoolConstantEntityTypeProvider::BOOL_CONSTANT_NAME, name)
			->attribute(BoolConstantEntityTypeProvider::BOOL_CONSTANT_VALUE, value)
			->build();
	}

}
}
}
