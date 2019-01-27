// Inexor entity system
// (c)2018 Inexor

#include "FloatConstantFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	FloatConstantFactory::FloatConstantFactory(
		shared_ptr<FloatConstantEntityTypeProvider> entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
	)
	{
		this->entity_type_provider = entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
	}

	FloatConstantFactory::~FloatConstantFactory()
	{
	}

	O_ENT_INST FloatConstantFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(entity_type_provider->get_type())
			->attribute("name", "")
			->attribute("value", 0.0f)
			->build();
	}

	O_ENT_INST FloatConstantFactory::create_instance(const string& name, const float& value)
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
