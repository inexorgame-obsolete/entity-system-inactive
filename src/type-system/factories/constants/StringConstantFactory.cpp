// Inexor entity system
// (c)2018 Inexor

#include "StringConstantFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	StringConstantFactory::StringConstantFactory(
		shared_ptr<StringConstantEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	StringConstantFactory::~StringConstantFactory()
	{
	}

	O_ENT_INST StringConstantFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("name", "")
			->attribute("value", "")
			->build();
	}

	O_ENT_INST StringConstantFactory::create_instance(const string& name, const string& value)
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
