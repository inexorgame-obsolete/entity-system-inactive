#include "RandomNextIntFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	RandomNextIntFactory::RandomNextIntFactory(
		RandomNextIntEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	RandomNextIntFactory::~RandomNextIntFactory()
	{
	}

	void RandomNextIntFactory::init()
	{
	}

	EntityInstancePtrOpt RandomNextIntFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_ON_ACTIVATION, false)
			->attribute(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_MIN, 0)
			->attribute(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_MAX, 1)
			->attribute(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_VALUE, 0)
			->build();
	}

	EntityInstancePtrOpt RandomNextIntFactory::create_instance(int min, int max)
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_ON_ACTIVATION, false)
			->attribute(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_MIN, min)
			->attribute(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_MAX, max)
			->attribute(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_VALUE, min)
			->build();
	}

}
}
}
