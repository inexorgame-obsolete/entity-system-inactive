#include "LowerThanIntFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LowerThanIntFactory::LowerThanIntFactory(
		LowerThanIntEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	LowerThanIntFactory::~LowerThanIntFactory()
	{
	}

	void LowerThanIntFactory::init()
	{
	}

	EntityInstancePtrOpt LowerThanIntFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(LowerThanIntEntityTypeProvider::LOWER_THAN_INT_INPUT_1, 0)
			->attribute(LowerThanIntEntityTypeProvider::LOWER_THAN_INT_INPUT_2, 0)
			->attribute(LowerThanIntEntityTypeProvider::LOWER_THAN_INT_RESULT, false)
			->build();
	}

}
}
}
