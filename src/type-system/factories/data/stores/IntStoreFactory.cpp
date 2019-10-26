#include "IntStoreFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	IntStoreFactory::IntStoreFactory(
		IntStoreEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	IntStoreFactory::~IntStoreFactory()
	{
	}

	void IntStoreFactory::init()
	{
	}

	EntityInstancePtrOpt IntStoreFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(IntStoreEntityTypeProvider::INT_STORE_NAME, "")
			->attribute(IntStoreEntityTypeProvider::INT_STORE_INPUT_VALUE, 0)
			->attribute(IntStoreEntityTypeProvider::INT_STORE_DEFAULT_VALUE, 0)
			->attribute(IntStoreEntityTypeProvider::INT_STORE_OUTPUT_VALUE, 0)
			->build();
	}

	EntityInstancePtrOpt IntStoreFactory::create_instance(const std::string& name, const int& input_value, const int& default_value, const int& output_value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(IntStoreEntityTypeProvider::INT_STORE_NAME, name)
			->attribute(IntStoreEntityTypeProvider::INT_STORE_INPUT_VALUE, input_value)
			->attribute(IntStoreEntityTypeProvider::INT_STORE_DEFAULT_VALUE, default_value)
			->attribute(IntStoreEntityTypeProvider::INT_STORE_OUTPUT_VALUE, output_value)
			->build();
	}

}
}
}
