// Inexor entity system
// (c)2018 Inexor

#include "ConstantsTypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	ConstantsTypeSystemManager::ConstantsTypeSystemManager(
		shared_ptr<IntConstantEntityTypeProvider> int_constant_entity_type_provider
	)
	{
		this->int_constant_entity_type_provider = int_constant_entity_type_provider;
	}

	ConstantsTypeSystemManager::~ConstantsTypeSystemManager()
	{
	}

}
}
}
