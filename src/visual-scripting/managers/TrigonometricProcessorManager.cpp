// Inexor entity system
// (c)2018 Inexor

#include "TrigonometricProcessorManager.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {


	TrigonometricProcessorManager::TrigonometricProcessorManager(
		std::shared_ptr<inexor::visual_scripting::ProcessorRegistry> processor_registry,
		std::shared_ptr<inexor::visual_scripting::Sin> sin
	)
	{
		this->processor_registry = processor_registry;
		this->sin = sin;
	}

	TrigonometricProcessorManager::~TrigonometricProcessorManager()
	{
	}

	void TrigonometricProcessorManager::init()
	{
		processor_registry->init();
		sin->init();

	}


}
}
