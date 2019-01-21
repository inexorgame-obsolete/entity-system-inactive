// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityInstanceManager.hpp"


namespace inexor {
namespace entity_system {

    
	EntityInstanceManager::EntityInstanceManager(
		std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
	) : InstanceManagerTemplate()
	{
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
	}

	
	EntityInstanceManager::~EntityInstanceManager()
	{
		// TODO: Implement!
	}


	std::optional<ENT_INST> EntityInstanceManager::create_entity_instance(const ENT_TYPE& ent_type)
	{
		// Create a new entity type instance.
		ENT_INST new_ent_instance = std::make_shared<EntityInstance>(ent_type);

		// Create all entity attribute type instances for this entity type instance.
		//std::vector<ENT_ATTR_TYPE> ent_type_attributes = ent_type->get_linked_attribute_types();
    /*
		for(std::size_t i=0; i<ent_type_attributes.size(); i++)
		{
			// Create an entity attribute type instance and store it in the map.
			// Use the entity system's EntityAttributeInstanceManager method!
			// TODO: FIX: Create instances!
            //ENT_ATTR_INST new_ent_attr_instance = ?->create_entity_attribute_instance(ent_type_attributes[i]);
			// create_entity_attribute_instance

			// Call template base class method.
			// FIX!
            //new_ent_instance->add_entity_attribute_instance(ent_type_attributes[i], new_ent_attr_instance);
		}*/

		// Call template base class method.
		add_instance(new_ent_instance->get_GUID(), new_ent_instance);
		
        return std::optional<ENT_INST> { new_ent_instance };
	}


	std::size_t EntityInstanceManager::get_entity_instance_count() const
	{
		// Call template base class method.
		return get_instance_count();
	}


	void EntityInstanceManager::delete_all_entity_instances()
	{
		// Call template base class method.
		delete_all_instances();
	}

    // TODO: Implement!
    /*
	const std::size_t EntityInstanceManager::get_entity_instances_count_of_type(const ENT_TYPE&)
	{
		// Call template base class method.
	}


	const std::vector<ENT_INST> EntityInstanceManager::get_all_entity_instances() const
	{
		// Call template base class method.
	}


	const std::vector<ENT_INST> EntityInstanceManager::get_all_entity_instances_of_type(const ENT_TYPE&)
	{
		// Call template base class method.
	}
	*/

};
};
