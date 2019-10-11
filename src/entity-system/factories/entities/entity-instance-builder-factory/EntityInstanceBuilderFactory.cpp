#include "EntityInstanceBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	EntityInstanceBuilderFactory::EntityInstanceBuilderFactory(
		EntityInstanceManagerPtr entity_instance_manager,
		EntityTypeManagerPtr entity_type_manager
	)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_factory);

		this->entity_instance_manager = entity_instance_manager;
		this->entity_type_manager = entity_type_manager;
	}

	EntityInstanceBuilderFactory::~EntityInstanceBuilderFactory()
	{
	}

	void EntityInstanceBuilderFactory::init()
	{
	}

	EntityInstanceBuilderPtr EntityInstanceBuilderFactory::get_builder()
	{
		// No mutex required as this is a read-only operation.
		return std::make_shared<EntityInstanceBuilder>(entity_instance_manager, entity_type_manager);
	}

}
}
