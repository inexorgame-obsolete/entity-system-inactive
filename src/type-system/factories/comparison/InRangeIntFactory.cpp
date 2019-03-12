#include "InRangeIntFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	InRangeIntFactory::InRangeIntFactory(
		InRangeIntEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	InRangeIntFactory::~InRangeIntFactory()
	{
	}

	void InRangeIntFactory::init()
	{
	}

	EntityInstancePtrOpt InRangeIntFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(InRangeIntEntityTypeProvider::IN_RANGE_INT_INPUT, 0)
			->attribute(InRangeIntEntityTypeProvider::IN_RANGE_INT_MIN, 0)
			->attribute(InRangeIntEntityTypeProvider::IN_RANGE_INT_MAX, 0)
			->attribute(InRangeIntEntityTypeProvider::IN_RANGE_INT_RESULT, true)
			->build();
	}

}
}
}
