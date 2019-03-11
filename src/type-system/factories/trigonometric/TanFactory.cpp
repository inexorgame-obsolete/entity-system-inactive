#include "TanFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TanFactory::TanFactory(
		TanEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	TanFactory::~TanFactory()
	{
	}

	void TanFactory::init()
	{
	}

	EntityInstancePtrOpt TanFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(TanEntityTypeProvider::TAN_VALUE, 0.0f)
			->build();
	}

}
}
}
