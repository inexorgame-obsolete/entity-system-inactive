#include "TriangleFactory.hpp"

namespace inexor {
namespace renderer {

	TriangleFactory::TriangleFactory(
		TriangleEntityTypeProviderPtr triangle_entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory,
		EntityInstanceManagerPtr entity_instance_manager
	)
	{
		this->triangle_entity_type_provider = triangle_entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
		this->entity_instance_manager = entity_instance_manager;
	}

	TriangleFactory::~TriangleFactory()
	{
	}

	EntityInstancePtrOpt TriangleFactory::create_instance(float x, float y)
	{
		return this->entity_instance_builder_factory->get_builder()
		->type(triangle_entity_type_provider->get_type())
		->attribute(TriangleEntityTypeProvider::TRIANGLE_X, x)
		->attribute(TriangleEntityTypeProvider::TRIANGLE_Y, y)
		->build();
	}

}
}
