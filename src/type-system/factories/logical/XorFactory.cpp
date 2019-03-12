#include "XorFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	XorFactory::XorFactory(
		XorEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	XorFactory::~XorFactory()
	{
	}

	void XorFactory::init()
	{
	}

	EntityInstancePtrOpt XorFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(XorEntityTypeProvider::XOR_INPUT_1, false)
			->attribute(XorEntityTypeProvider::XOR_INPUT_1, false)
			->attribute(XorEntityTypeProvider::XOR_RESULT, false)
			->build();
	}

}
}
}
