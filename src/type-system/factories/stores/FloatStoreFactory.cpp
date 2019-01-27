// Inexor entity system
// (c)2018 Inexor

#include "FloatStoreFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	FloatStoreFactory::FloatStoreFactory(
		shared_ptr<FloatStoreEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	FloatStoreFactory::~FloatStoreFactory()
	{
	}

	O_ENT_INST FloatStoreFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("name", "")
			->attribute("input_value", 0)
			->attribute("default_value", 0)
			->attribute("output_value", 0)
			->build();
	}

	O_ENT_INST FloatStoreFactory::create_instance(const string& name, const float& input_value, const float& default_value, const float& output_value)
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
