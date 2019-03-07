// Inexor entity system
// (c)2018 Inexor

#include "ArithmeticTypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	ArithmeticTypeSystemManager::ArithmeticTypeSystemManager(
		shared_ptr<AddIntEntityTypeProvider> add_int_entity_type_provider,
		shared_ptr<AddIntFactory> add_int_factory
	)
	{
		this->add_int_entity_type_provider = add_int_entity_type_provider;
		this->add_int_factory = add_int_factory;
	}

	ArithmeticTypeSystemManager::~ArithmeticTypeSystemManager()
	{
	}

	void ArithmeticTypeSystemManager::init()
	{
	}

}
}
}
