// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {

    
	EntityTypeInstanceManager::EntityTypeInstanceManager()
	{
	}

	
	EntityTypeInstanceManager::~EntityTypeInstanceManager()
	{
	}


	std::shared_ptr<EntityTypeInstance> EntityTypeInstanceManager::create_entity_type_instance(const std::shared_ptr<EntityType>& entity_type_pointer)
	{
		// Create a new entity type instance.
		std::shared_ptr<EntityTypeInstance> new_ent_type_instance = std::make_shared<EntityTypeInstance>(entity_type_pointer);
		// Call template class backend method.
		add_instance_to_buffer(new_ent_type_instance);
		return new_ent_type_instance;
	}


	const std::size_t EntityTypeInstanceManager::get_entity_type_instance_count() const
	{
		// Call template class backend method.
		return get_type_instance_count();
	}


	void EntityTypeInstanceManager::delete_all_entity_type_instances()
	{
		// Call template class backend method.
		delete_all_type_instances();
	}


};
};
