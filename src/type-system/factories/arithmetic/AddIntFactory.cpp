#include "AddIntFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	AddIntFactory::AddIntFactory(
		AddIntEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	AddIntFactory::~AddIntFactory()
	{
	}

	void AddIntFactory::init()
	{
	}

	EntityInstancePtrOpt AddIntFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(AddIntEntityTypeProvider::ADD_INT_AUGEND, 0)
			->attribute(AddIntEntityTypeProvider::ADD_INT_ADDEND, 0)
			->attribute(AddIntEntityTypeProvider::ADD_INT_SUM, 0)
			->build();
	}

}
}
}
