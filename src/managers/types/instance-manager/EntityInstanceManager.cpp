// Inexor entity system prototype
// (c)2018-2019 Inexor

#include "EntityInstanceManager.hpp"


namespace inexor {
namespace entity_system {

    
	EntityInstanceManager::EntityInstanceManager() : InstanceManagerTemplate(entity_type_instance_error)
	{
		// TODO: Implement!
	}

	
	EntityInstanceManager::~EntityInstanceManager()
	{
		// TODO: Implement!
	}


	ENT_INST EntityInstanceManager::create_entity_type_instance(const ENT_TYPE& ent_type)
	{
		// Create a new entity type instance.
		ENT_INST new_ent_type_instance = std::make_shared<EntityInstance>(ent_type);
		
		// Call template base class method.
		add_instance(new_ent_type_instance->get_GUID(), new_ent_type_instance);
		
		return new_ent_type_instance;
	}


	const std::size_t EntityInstanceManager::get_entity_type_instance_count() const
	{
		// Call template base class method.
		return get_instance_count();
	}


	void EntityInstanceManager::delete_all_entity_type_instances()
	{
		// Call template base class method.
		delete_all_instances();
	}

    // TODO: Implement!
    /*
	const std::size_t EntityInstanceManager::get_entity_type_instances_count_of_type(const ENT_TYPE&)
	{
		// Call template base class method.
	}


	const std::vector<ENT_TYPE_INST> EntityInstanceManager::get_all_entity_type_instances() const
	{
		// Call template base class method.
	}


	const std::vector<ENT_TYPE_INST> EntityInstanceManager::get_all_entity_type_instances_of_type(const ENT_TYPE&)
	{
		// Call template base class method.
	}
	*/

};
};
