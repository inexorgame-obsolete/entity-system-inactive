// Inexor entity system
// (c)2018 Inexor

#include "AddIntFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	AddIntFactory::AddIntFactory(
		shared_ptr<AddIntEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	AddIntFactory::~AddIntFactory()
	{
	}

	O_ENT_INST AddIntFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("augend", 0)
			->attribute("addend", 0)
			->attribute("sum", 0)
			->build();
	}

}
}
}
