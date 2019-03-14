#include "StringStoreFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	StringStoreFactory::StringStoreFactory(
		StringStoreEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	StringStoreFactory::~StringStoreFactory()
	{
	}

	void StringStoreFactory::init()
	{
	}

	EntityInstancePtrOpt StringStoreFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(StringStoreEntityTypeProvider::STRING_STORE_NAME, "")
			->attribute(StringStoreEntityTypeProvider::STRING_STORE_INPUT_VALUE, "")
			->attribute(StringStoreEntityTypeProvider::STRING_STORE_DEFAULT_VALUE, "")
			->attribute(StringStoreEntityTypeProvider::STRING_STORE_OUTPUT_VALUE, "")
			->build();
	}

	EntityInstancePtrOpt StringStoreFactory::create_instance(const string& name, const string& input_value, const string& default_value, const string& output_value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(StringStoreEntityTypeProvider::STRING_STORE_NAME, name)
			->attribute(StringStoreEntityTypeProvider::STRING_STORE_INPUT_VALUE, input_value)
			->attribute(StringStoreEntityTypeProvider::STRING_STORE_DEFAULT_VALUE, default_value)
			->attribute(StringStoreEntityTypeProvider::STRING_STORE_OUTPUT_VALUE, output_value)
			->build();
	}

}
}
}
