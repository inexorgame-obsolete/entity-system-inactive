#include "StringConstantFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	StringConstantFactory::StringConstantFactory(
		StringConstantEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	StringConstantFactory::~StringConstantFactory()
	{
	}

	void StringConstantFactory::init()
	{
	}

	EntityInstancePtrOpt StringConstantFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(StringConstantEntityTypeProvider::STRING_CONSTANT_NAME, "")
			->attribute(StringConstantEntityTypeProvider::STRING_CONSTANT_VALUE, "")
			->build();
	}

	EntityInstancePtrOpt StringConstantFactory::create_instance(const std::string& name)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(StringConstantEntityTypeProvider::STRING_CONSTANT_NAME, name)
			->attribute(StringConstantEntityTypeProvider::STRING_CONSTANT_VALUE, "")
			->build();
	}

	EntityInstancePtrOpt StringConstantFactory::create_instance(const std::string& name, const std::string& value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(StringConstantEntityTypeProvider::STRING_CONSTANT_NAME, name)
			->attribute(StringConstantEntityTypeProvider::STRING_CONSTANT_VALUE, value)
			->build();
	}

}
}
}
