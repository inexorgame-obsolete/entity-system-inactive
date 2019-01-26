// Inexor entity system
// (c)2018 Inexor

#include "EntityTypeBuilderManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {


	EntityTypeBuilderManager::EntityTypeBuilderManager(
		shared_ptr<EntityTypeManager> entity_type_manager,
		shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager,
		shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
	)
	{
		this->entity_type_manager = entity_type_manager;
		this->entity_attribute_type_manager = entity_attribute_type_manager;
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
	}

	EntityTypeBuilderManager::~EntityTypeBuilderManager()
	{
	}

	void EntityTypeBuilderManager::init()
	{
	}

	shared_ptr<EntityTypeBuilder> EntityTypeBuilderManager::get_builder() {
		return make_shared<EntityTypeBuilder>(entity_type_manager, entity_attribute_type_manager, entity_attribute_instance_manager);
	}

}
}
