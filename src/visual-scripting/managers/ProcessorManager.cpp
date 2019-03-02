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

//	void ProcessorManager::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
//	{
//		// Get entity type
//		std::shared_ptr<inexor::entity_system::EntityType> entity_type = entity_instance->get_entity_type();
//		std::cout << "Entity instance [" << entity_instance->get_GUID().str() << "] of type [" << entity_type->get_type_name() << "] created" << std::endl;
//
//		// Get processor for entity type
//		std::optional<std::shared_ptr<Processor>> o_processor = processor_registry->get_processor(entity_type);
//
//		if (o_processor.has_value())
//		{
//			std::shared_ptr<Processor> processor = o_processor.value();
//			std::cout << "Entity type [" << entity_type->get_type_name() << "] has processor" << std::endl;
//			processor->init_entity_instance(entity_instance);
//		} else {
//			std::cout << "Entity type [" << entity_type->get_type_name() << "] has no processor" << std::endl;
//		}
//	}
//
//	void ProcessorManager::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
//	{
//		// Disconnect observers with execution method
//		// Delete observer for each input atttribute of the entity instance
//	}


}
}
