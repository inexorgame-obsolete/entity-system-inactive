// Inexor entity system
// (c)2018 Inexor

#include "SinFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	SinFactory::SinFactory(
		shared_ptr<SinEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	SinFactory::~SinFactory()
	{
	}

	O_ENT_INST SinFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("sin_value", 0.0f)
			->build();
	}

}
}
}
