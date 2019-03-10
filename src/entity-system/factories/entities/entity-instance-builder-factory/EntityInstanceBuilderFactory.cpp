#include "EntityInstanceBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	EntityInstanceBuilderFactory::EntityInstanceBuilderFactory(
		EntityInstanceManagerPtr entity_instance_manager,
		EntityTypeManagerPtr entity_type_manager
	)
	{
		this->entity_instance_manager = entity_instance_manager;
		this->entity_type_manager = entity_type_manager;
	}

	EntityInstanceBuilderFactory::~EntityInstanceBuilderFactory()
	{
	}

	void EntityInstanceBuilderFactory::init()
	{
	}

	EntityInstanceBuilderPtr EntityInstanceBuilderFactory::get_builder() {
		return std::make_shared<EntityInstanceBuilder>(entity_instance_manager, entity_type_manager);
	}

}
}
