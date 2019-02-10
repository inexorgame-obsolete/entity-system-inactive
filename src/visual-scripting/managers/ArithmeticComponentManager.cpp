// Inexor entity system
// (c)2018 Inexor

#include "ArithmeticComponentManager.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

namespace inexor {
namespace visual_scripting {


	ArithmeticComponentManager::ArithmeticComponentManager(
		shared_ptr<ActiveComponentRegistry> active_component_registry,
		shared_ptr<AddInt> add_int
	)
	{
		this->active_component_registry = active_component_registry;
		this->add_int = add_int;
	}

	ArithmeticComponentManager::~ArithmeticComponentManager()
	{
	}

	void ArithmeticComponentManager::init()
	{
		active_component_registry->register_active_component(add_int);
	}


}
}
