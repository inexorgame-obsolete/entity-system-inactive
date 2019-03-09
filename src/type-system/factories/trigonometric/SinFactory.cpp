#include "SinFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	SinFactory::SinFactory(
		SinEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	SinFactory::~SinFactory()
	{
	}

	std::optional<std::shared_ptr<EntityInstance> > SinFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(SinEntityTypeProvider::SIN_VALUE, 0.0f)
			->build();
	}

}
}
}
