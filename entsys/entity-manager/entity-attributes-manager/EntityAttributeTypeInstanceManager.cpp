// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeInstanceManager.hpp"
#include "../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	extern std::shared_ptr<EntitySystem> entsys;


    EntityAttributeTypeInstanceManager::EntityAttributeTypeInstanceManager()
    {
    }


    EntityAttributeTypeInstanceManager::~EntityAttributeTypeInstanceManager()
    {
    }


	std::shared_ptr<EntityAttributeTypeInstance> EntityAttributeTypeInstanceManager::create_entity_attribute_type_instance(
		const std::shared_ptr<EntityAttributeType>& ent_attr_type)
	{
		// Create entity attribute type instance.
		std::shared_ptr<EntityAttributeTypeInstance> new_ent_attr_type_instance
			= std::make_shared<EntityAttributeTypeInstance>(ent_attr_type);

		// Call base template class method.
		add_instance_to_buffer(new_ent_attr_type_instance);

		return new_ent_attr_type_instance;
	}


	const std::size_t EntityAttributeTypeInstanceManager::get_entity_attribute_type_instance_count() const
	{
		return get_type_instance_count();
	}

	
	void EntityAttributeTypeInstanceManager::delete_all_entity_attribute_type_instances()
	{
		delete_all_type_instances();
	}


};
};
