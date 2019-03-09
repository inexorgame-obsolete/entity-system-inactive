#include "CosFactory.hpp"

using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	CosFactory::CosFactory(
		CosEntityTypeProviderPtr entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	CosFactory::~CosFactory()
	{
	}

	O_ENT_INST CosFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(CosEntityTypeProvider::COS_VALUE, 0.0f)
			->build();
	}

}
}
}
