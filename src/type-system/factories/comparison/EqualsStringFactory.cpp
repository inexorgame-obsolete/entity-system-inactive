#include "EqualsStringFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	EqualsStringFactory::EqualsStringFactory(
		EqualsStringEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	EqualsStringFactory::~EqualsStringFactory()
	{
	}

	void EqualsStringFactory::init()
	{
	}

	EntityInstancePtrOpt EqualsStringFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(EqualsStringEntityTypeProvider::EQUALS_STRING_INPUT_1, "")
			->attribute(EqualsStringEntityTypeProvider::EQUALS_STRING_INPUT_2, "")
			->attribute(EqualsStringEntityTypeProvider::EQUALS_STRING_RESULT, true)
			->build();
	}

}
}
}
