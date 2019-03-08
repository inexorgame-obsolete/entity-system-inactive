#include "CosFactory.hpp"

using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	CosFactory::CosFactory(
		shared_ptr<CosEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	CosFactory::~CosFactory()
	{
	}

	O_ENT_INST CosFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute(CosEntityTypeProvider::COS_VALUE, 0.0f)
			->build();
	}

}
}
}
