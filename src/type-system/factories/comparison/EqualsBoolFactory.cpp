#include "EqualsBoolFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	EqualsBoolFactory::EqualsBoolFactory(
		EqualsBoolEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	EqualsBoolFactory::~EqualsBoolFactory()
	{
	}

	void EqualsBoolFactory::init()
	{
	}

	EntityInstancePtrOpt EqualsBoolFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(EqualsBoolEntityTypeProvider::EQUALS_BOOL_INPUT_1, false)
			->attribute(EqualsBoolEntityTypeProvider::EQUALS_BOOL_INPUT_2, false)
			->attribute(EqualsBoolEntityTypeProvider::EQUALS_BOOL_RESULT, true)
			->build();
	}

}
}
}
