// Inexor entity system
// (c)2018 Inexor

#include "ProcessorManager.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {


	ProcessorManager::ProcessorManager(
		std::shared_ptr<ProcessorRegistry> processor_registry,
		std::shared_ptr<ArithmeticProcessorManager> arithmetic_processor_manager
	)
	{
		this->processor_registry = processor_registry;
		this->arithmetic_processor_manager = arithmetic_processor_manager;
	}

	ProcessorManager::~ProcessorManager()
	{
	}

	void ProcessorManager::init()
	{
		this->processor_registry->init();
		this->arithmetic_processor_manager->init();
	}

	void ProcessorManager::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
	{
		// Get entity type
		std::shared_ptr<EntityType> entity_type = entity_instance->get_entity_type();
		// Get processor for entity type
		std::optional<std::shared_ptr<Processor>> o_processor = processor_registry->get_processor_by_entity_type(entity_type);

		if (o_processor.has_value())
		{
			std::shared_ptr<Processor> processor = o_processor.value();
			// TODO: Get execution method for processor
			// processor->execute(entity_instance);
			// TODO: Create observer for each input atttribute of the entity instance
			// TODO: Connect observers with execution method
		}
	}

	void ProcessorManager::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
	}


}
}
