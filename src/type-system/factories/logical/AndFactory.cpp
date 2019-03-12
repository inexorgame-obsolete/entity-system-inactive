#include "AndFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	AndFactory::AndFactory(
		AndEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	AndFactory::~AndFactory()
	{
	}

	void AndFactory::init()
	{
	}

	EntityInstancePtrOpt AndFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(AndEntityTypeProvider::AND_INPUT_1, false)
			->attribute(AndEntityTypeProvider::AND_INPUT_2, false)
			->attribute(AndEntityTypeProvider::AND_RESULT, false)
			->build();
	}

}
}
}
