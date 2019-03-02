// Inexor entity system
// (c)2018 Inexor

#include "ArithmeticProcessorManager.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {


	ArithmeticProcessorManager::ArithmeticProcessorManager(
		std::shared_ptr<inexor::visual_scripting::ProcessorRegistry> processor_registry,
		std::shared_ptr<inexor::visual_scripting::AddInt> add_int
	)
	{
		this->processor_registry = processor_registry;
		this->add_int = add_int;
	}

	ArithmeticProcessorManager::~ArithmeticProcessorManager()
	{
	}

	void ArithmeticProcessorManager::init()
	{
		processor_registry->init();
		add_int->init();
	}


}
}
