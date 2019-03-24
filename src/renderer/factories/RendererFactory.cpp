#include "RendererFactory.hpp"

namespace inexor {
namespace renderer {

	RendererFactory::RendererFactory(
		RendererEntityTypeProviderPtr renderer_entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory,
		EntityInstanceManagerPtr entity_instance_manager
	)
	{
		this->renderer_entity_type_provider = renderer_entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
		this->entity_instance_manager = entity_instance_manager;
	}

	RendererFactory::~RendererFactory()
    {
	}

    EntityInstancePtrOpt RendererFactory::create_instance(float x, float y)
    {
		return this->entity_instance_builder_factory->get_builder()
			->type(renderer_entity_type_provider->get_type())
			->attribute(RendererEntityTypeProvider::RENDERER_X, x)
			->attribute(RendererEntityTypeProvider::RENDERER_Y, y)
			->build();
	}

}
}
