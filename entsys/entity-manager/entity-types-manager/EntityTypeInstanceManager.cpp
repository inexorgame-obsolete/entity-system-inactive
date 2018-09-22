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


	ENTSYS_RESULT EntityTypeInstanceManager::register_entity_type_instance(const std::shared_ptr<EntityTypeInstance>& param_entity_type)
	{
		// Add this instance to global entity type instance buffer!
		global_entity_type_instance_buffer.push_back(param_entity_type);

		// TODO: Implement!
		return ENTSYS_ERROR;
	}


	const std::size_t EntityTypeInstanceManager::get_entity_type_instance_count() const
	{
		return global_entity_type_instance_buffer.size();
	}


	void EntityTypeInstanceManager::delete_all_entity_type_instances()
	{
		global_entity_type_instance_buffer.clear();
	}


};
};
