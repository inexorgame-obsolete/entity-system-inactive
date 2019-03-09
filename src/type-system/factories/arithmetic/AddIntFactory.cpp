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
		shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	AddIntFactory::~AddIntFactory()
	{
	}

	O_ENT_INST AddIntFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("add_int_augend", 0)
			->attribute("add_int_addend", 0)
			->attribute("add_int_sum", 0)
			->build();
	}

}
}
}
