// Inexor entity system
// (c)2018 Inexor

#include "ActiveComponentManager.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {


	ActiveComponentManager::ActiveComponentManager(
		std::shared_ptr<ActiveComponentRegistry> active_component_registry,
		std::shared_ptr<ArithmeticComponentManager> arithmetic_component_manager
	)
	{
		this->active_component_registry = active_component_registry;
		this->arithmetic_component_manager = arithmetic_component_manager;
	}

	ActiveComponentManager::~ActiveComponentManager()
	{
	}

	void ActiveComponentManager::init()
	{
		this->active_component_registry->init();
		this->arithmetic_component_manager->init();
	}

	void ActiveComponentManager::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
	{
		// Get entity type
		std::shared_ptr<EntityType> entity_type = entity_instance->get_entity_type();
		// Get active component for entity type
		std::optional<std::shared_ptr<ActiveComponent>> o_active_component = active_component_registry->get_active_component_by_entity_type(entity_type);

		if (o_active_component.has_value())
		{
			std::shared_ptr<ActiveComponent> active_component = o_active_component.value();
			// TODO: Get execution method for active component
			// active_component->execute(entity_instance);
			// TODO: Create observer for each input atttribute of the entity instance
			// TODO: Connect observers with execution method
		}
	}

	void ActiveComponentManager::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
	}


}
}
