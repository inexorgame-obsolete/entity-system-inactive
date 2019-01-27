// Inexor entity system
// (c)2018 Inexor

#include "TypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	TypeSystemManager::TypeSystemManager(
		shared_ptr<ConstantsTypeSystemManager> constants_type_system_manager,
		shared_ptr<StoresTypeSystemManager> stores_type_system_manager,
		shared_ptr<ConvertersTypeSystemManager> converters_type_system_manager
	)
	{
		this->constants_type_system_manager = constants_type_system_manager;
		this->stores_type_system_manager = stores_type_system_manager;
		this->converters_type_system_manager = converters_type_system_manager;
	}

	TypeSystemManager::~TypeSystemManager()
	{
	}

	void TypeSystemManager::init()
	{
		constants_type_system_manager->init();
		stores_type_system_manager->init();
		converters_type_system_manager->init();
	}

}
}
}
