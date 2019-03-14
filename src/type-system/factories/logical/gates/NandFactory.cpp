#include "NandFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	NandFactory::NandFactory(
		NandEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	NandFactory::~NandFactory()
	{
	}

	void NandFactory::init()
	{
	}

	EntityInstancePtrOpt NandFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(NandEntityTypeProvider::NAND_INPUT_1, false)
			->attribute(NandEntityTypeProvider::NAND_INPUT_2, false)
			->attribute(NandEntityTypeProvider::NAND_RESULT, true)
			->build();
	}

}
}
}
