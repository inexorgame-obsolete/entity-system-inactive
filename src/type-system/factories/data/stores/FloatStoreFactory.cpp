#include "FloatStoreFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	FloatStoreFactory::FloatStoreFactory(
		FloatStoreEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	FloatStoreFactory::~FloatStoreFactory()
	{
	}

	void FloatStoreFactory::init()
	{
	}

	EntityInstancePtrOpt FloatStoreFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(FloatStoreEntityTypeProvider::FLOAT_STORE_NAME, "")
			->attribute(FloatStoreEntityTypeProvider::FLOAT_STORE_INPUT_VALUE, 0.0f)
			->attribute(FloatStoreEntityTypeProvider::FLOAT_STORE_DEFAULT_VALUE, 0.0f)
			->attribute(FloatStoreEntityTypeProvider::FLOAT_STORE_OUTPUT_VALUE, 0.0f)
			->build();
	}

	EntityInstancePtrOpt FloatStoreFactory::create_instance(const string& name, const float& input_value, const float& default_value, const float& output_value)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(FloatStoreEntityTypeProvider::FLOAT_STORE_NAME, name)
			->attribute(FloatStoreEntityTypeProvider::FLOAT_STORE_INPUT_VALUE, input_value)
			->attribute(FloatStoreEntityTypeProvider::FLOAT_STORE_DEFAULT_VALUE, default_value)
			->attribute(FloatStoreEntityTypeProvider::FLOAT_STORE_OUTPUT_VALUE, output_value)
			->build();
	}

}
}
}
