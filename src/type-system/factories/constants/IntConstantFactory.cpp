// Inexor entity system
// (c)2018 Inexor

#include "IntConstantFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	IntConstantFactory::IntConstantFactory(
		shared_ptr<IntConstantEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	IntConstantFactory::~IntConstantFactory()
	{
	}

	O_ENT_INST IntConstantFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("name", "")
			->attribute("value", 0)
			->build();
	}

	O_ENT_INST IntConstantFactory::create_instance(const string& name, const int& value)
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
