// Inexor entity system
// (c)2018 Inexor

#include "StringStoreFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	StringStoreFactory::StringStoreFactory(
		shared_ptr<StringStoreEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	StringStoreFactory::~StringStoreFactory()
	{
	}

	O_ENT_INST StringStoreFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("name", "")
			->attribute("input_value", "")
			->attribute("default_value", "")
			->attribute("output_value", "")
			->build();
	}

	O_ENT_INST StringStoreFactory::create_instance(const string& name, const string& input_value, const string& default_value, const string& output_value)
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("name", name)
			->attribute("input_value", input_value)
			->attribute("default_value", default_value)
			->attribute("output_value", output_value)
			->build();
	}

}
}
}
