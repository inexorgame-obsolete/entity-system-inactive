// Inexor entity system
// (c)2018 Inexor

#include "ActiveComponentManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace visual_scripting {


	ActiveComponentManager::ActiveComponentManager(
		shared_ptr<ActiveComponentRegistry> active_component_registry,
		shared_ptr<ArithmeticComponentManager> arithmetic_component_manager
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


}
}
