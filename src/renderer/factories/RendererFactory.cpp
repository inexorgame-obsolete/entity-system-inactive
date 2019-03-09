#include "RendererFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace renderer {

	RendererFactory::RendererFactory(
		shared_ptr<RendererEntityTypeProvider> renderer_entity_type_provider,
		shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory,
		shared_ptr<EntityInstanceManager> entity_instance_manager
	)
	{
		this->renderer_entity_type_provider = renderer_entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
		this->entity_instance_manager = entity_instance_manager;
	}

	RendererFactory::~RendererFactory() {
	}

	O_ENT_INST RendererFactory::create_instance(float x, float y) {
		return this->entity_instance_builder_factory->get_builder()
			->type(this->renderer_entity_type_provider->get_type())
			->attribute(RendererEntityTypeProvider::RENDERER_X, x)
			->attribute(RendererEntityTypeProvider::RENDERER_Y, y)
			->build();
	}

}
}
