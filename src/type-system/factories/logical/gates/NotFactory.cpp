#include "NotFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	NotFactory::NotFactory(
		NotEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	NotFactory::~NotFactory()
	{
	}

	void NotFactory::init()
	{
	}

	EntityInstancePtrOpt NotFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(NotEntityTypeProvider::NOT_INPUT, false)
			->attribute(NotEntityTypeProvider::NOT_RESULT, true)
			->build();
	}

}
}
}
