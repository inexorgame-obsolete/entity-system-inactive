// Inexor entity system
// (c)2018 Inexor

#include "BoolConstantFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	BoolConstantFactory::BoolConstantFactory(
		shared_ptr<BoolConstantEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	BoolConstantFactory::~BoolConstantFactory()
	{
	}

	O_ENT_INST BoolConstantFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("name", "")
			->attribute("value", false)
			->build();
	}

	O_ENT_INST BoolConstantFactory::create_instance(const string& name, const bool& value)
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("name", name)
			->attribute("value", value)
			->build();
	}

}
}
}
