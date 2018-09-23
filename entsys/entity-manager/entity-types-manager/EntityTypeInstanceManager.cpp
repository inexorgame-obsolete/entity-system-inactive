// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {
    

    EntityTypeInstanceManager::EntityTypeInstanceManager()
    {
		// TODO: implement!
    }


    EntityTypeInstanceManager::~EntityTypeInstanceManager()
    {
		delete_all_entity_type_instances();
    }


	std::shared_ptr<EntityTypeInstance> EntityTypeInstanceManager::create_entity_type_instance(
		const std::shared_ptr<EntityType>& param_entity_type)
	{
		std::shared_ptr<EntityTypeInstance> new_ent_type_instance = std::make_shared<EntityTypeInstance>(param_entity_type);
		entity_type_instance_buffer.push_back(new_ent_type_instance);
		return new_ent_type_instance;
	}


	const std::size_t EntityTypeInstanceManager::get_entity_type_instance_count() const
	{
		return entity_type_instance_buffer.size();
	}


	void EntityTypeInstanceManager::delete_all_entity_type_instances()
	{
		entity_type_instance_buffer.clear();
	}


};
};
