#include "EqualsIntFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	EqualsIntFactory::EqualsIntFactory(
		EqualsIntEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	EqualsIntFactory::~EqualsIntFactory()
	{
	}

	void EqualsIntFactory::init()
	{
	}

	EntityInstancePtrOpt EqualsIntFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(EqualsIntEntityTypeProvider::EQUALS_INT_INPUT_1, 0)
			->attribute(EqualsIntEntityTypeProvider::EQUALS_INT_INPUT_2, 0)
			->attribute(EqualsIntEntityTypeProvider::EQUALS_INT_RESULT, true)
			->build();
	}

}
}
}
