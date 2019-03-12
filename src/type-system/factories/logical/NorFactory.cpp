#include "NorFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	NorFactory::NorFactory(
		NorEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	NorFactory::~NorFactory()
	{
	}

	void NorFactory::init()
	{
	}

	EntityInstancePtrOpt NorFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(NorEntityTypeProvider::NOR_INPUT_1, false)
			->attribute(NorEntityTypeProvider::NOR_INPUT_2, false)
			->attribute(NorEntityTypeProvider::NOR_RESULT, false)
			->build();
	}

}
}
}
