// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityAttributeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    EntityAttributeInstanceManager::EntityAttributeInstanceManager() : InstanceManagerTemplate()
    {
		// TODO: Implement!
    }


    EntityAttributeInstanceManager::~EntityAttributeInstanceManager()
    {
		// TODO: Implement!
    }


	std::optional<ENT_ATTR_INST> EntityAttributeInstanceManager::create_entity_attribute_instance(const ENT_ATTR_TYPE& ent_attr_type)
	{
		// Create entity attribute instance.
		ENT_ATTR_INST new_ent_attr_instance = std::make_shared<EntityAttributeInstance>(ent_attr_type);

        // 
        add_instance(new_ent_attr_instance->get_GUID(), new_ent_attr_instance);

        // 
        return std::optional<ENT_ATTR_INST> { new_ent_attr_instance };
	}
    

    std::size_t EntityAttributeInstanceManager::delete_entity_attribute_instance(const xg::Guid& ent_attr_type_GUID)
    {
        return delete_instance(ent_attr_type_GUID);
    }


	std::size_t EntityAttributeInstanceManager::get_entity_attribute_instance_count() const
	{
        // 
        return get_instance_count();
	}

	
	void EntityAttributeInstanceManager::delete_all_entity_attribute_instances()
	{
        // 
		delete_all_instances();
	}


};
};
