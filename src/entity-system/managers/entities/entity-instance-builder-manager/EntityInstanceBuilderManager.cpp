// Inexor entity system
// (c)2018 Inexor

#include "EntityInstanceBuilderManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {


	EntityInstanceBuilderManager::EntityInstanceBuilderManager(
		shared_ptr<EntityInstanceManager> entity_instance_manager,
		shared_ptr<EntityTypeManager> entity_type_manager
	)
	{
		this->entity_instance_manager = entity_instance_manager;
		this->entity_type_manager = entity_type_manager;
	}

	EntityInstanceBuilderManager::~EntityInstanceBuilderManager()
	{
	}

	void EntityInstanceBuilderManager::init()
	{
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilderManager::get_builder() {
		return make_shared<EntityInstanceBuilder>(entity_instance_manager, entity_type_manager);
	}

}
}
