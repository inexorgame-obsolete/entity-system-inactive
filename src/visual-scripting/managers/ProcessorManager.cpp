// Inexor entity system
// (c)2018 Inexor

#include "ProcessorManager.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {

	ProcessorManager::ProcessorManager(
		std::shared_ptr<ProcessorRegistry> processor_registry,
		std::shared_ptr<ArithmeticProcessorManager> arithmetic_processor_manager,
		std::shared_ptr<TrigonometricProcessorManager> trigonometric_processor_manager
	)
	{
		this->processor_registry = processor_registry;
		this->arithmetic_processor_manager = arithmetic_processor_manager;
		this->trigonometric_processor_manager = trigonometric_processor_manager;
	}

	ProcessorManager::~ProcessorManager()
	{
	}

	void ProcessorManager::init()
	{
		this->processor_registry->init();
		this->arithmetic_processor_manager->init();
		this->trigonometric_processor_manager->init();
	}

}
}
