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


	std::shared_ptr<EntityTypeInstance> EntityTypeInstanceManager::create_entity_type_instance(const std::shared_ptr<EntityType>& ent_type)
	{
		// Create a new entity type instance.
		std::shared_ptr<EntityTypeInstance> new_ent_type_instance = std::make_shared<EntityTypeInstance>(ent_type);
		
		// Call method of the template base class.
		add_instance_to_buffer(new_ent_type_instance);
		
		return new_ent_type_instance;
	}


	const std::size_t EntityTypeInstanceManager::get_entity_type_instance_count() const
	{
		// Call method of the template base class.
		return get_type_instance_count();
	}


	void EntityTypeInstanceManager::delete_all_entity_type_instances()
	{
		// Call method of the template base class.
		delete_all_type_instances();
	}


};
};
