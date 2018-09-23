// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    EntityAttributeTypeInstanceManager::EntityAttributeTypeInstanceManager()
    {
		// TODO: Implement!
    }


    EntityAttributeTypeInstanceManager::~EntityAttributeTypeInstanceManager()
    {
		// TODO: Implement!
    }


	std::shared_ptr<EntityAttributeTypeInstance> EntityAttributeTypeInstanceManager::create_entity_attribute_type_instance(
		const std::shared_ptr<EntityAttributeType>& param_ent_attr_type)
	{
		std::shared_ptr<EntityAttributeTypeInstance> new_ent_attr_type_instance = std::make_shared<EntityAttributeTypeInstance>(param_ent_attr_type);
		entity_attribute_type_instance_buffer.push_back(new_ent_attr_type_instance);
		return new_ent_attr_type_instance;
	}


	const std::size_t EntityAttributeTypeInstanceManager::get_entity_attribute_type_instance_count() const
	{
		return entity_attribute_type_instance_buffer.size();
	}


};
};
