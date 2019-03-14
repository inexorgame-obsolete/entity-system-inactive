#include "GreaterThanFloatFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	GreaterThanFloatFactory::GreaterThanFloatFactory(
		GreaterThanFloatEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	GreaterThanFloatFactory::~GreaterThanFloatFactory()
	{
	}

	void GreaterThanFloatFactory::init()
	{
	}

	EntityInstancePtrOpt GreaterThanFloatFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(GreaterThanFloatEntityTypeProvider::GREATER_THAN_FLOAT_INPUT_1, 0.0f)
			->attribute(GreaterThanFloatEntityTypeProvider::GREATER_THAN_FLOAT_INPUT_2, 0.0f)
			->attribute(GreaterThanFloatEntityTypeProvider::GREATER_THAN_FLOAT_RESULT, false)
			->build();
	}

}
}
}
