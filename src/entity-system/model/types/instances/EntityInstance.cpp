// Inexor entity system prototype
// (c)2018-2019 Inexor

#include "EntityInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityInstance::EntityInstance(const ENT_TYPE& ent_type) : InstanceBase(ent_type)
	{
	}


	EntityInstance::~EntityInstance()
	{
		// TODO: Implement!
	}


    void EntityInstance::add_entity_attribute_instance(const std::shared_ptr<EntityAttributeType>& ent_attr_type, const std::shared_ptr<EntityAttributeInstance>& ent_attr_inst)
    {
        // Use lock guard to ensure thread safety for this write operation!
        std::lock_guard<std::mutex> lock(entity_type_mutex);
        instances[ent_attr_type] = ent_attr_inst;
    }


	std::unordered_map<std::shared_ptr<EntityAttributeType>, std::shared_ptr<EntityAttributeInstance>> EntityInstance::get_instances() const
	{
		return instances;
	}


};
};
