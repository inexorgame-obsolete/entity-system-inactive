// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityInstance::EntityInstance(const ENT_TYPE& ent_type) : InstanceBase(ent_type)
	{
        // TODO: Implement!
	}


	EntityInstance::~EntityInstance()
	{
		// TODO: Implement!
	}


    void EntityInstance::add_entity_attribute_instance(const ENT_ATTR_TYPE& ent_attr_type, const ENT_ATTR_INST& ent_attr_inst)
    {
        // Use lock guard to ensure thread safety for this write operation!
        std::lock_guard<std::mutex> lock(entity_type_mutex);
        instances[ent_attr_type] = ent_attr_inst;
    }


	std::optional<std::unordered_map<ENT_ATTR_TYPE, ENT_ATTR_INST>> EntityInstance::get_instances() const
	{
        if(0 == instances.size())
        {
            return std::nullopt;
        }
        // Read only, no mutex required.
        return std::optional<std::unordered_map<ENT_ATTR_TYPE, ENT_ATTR_INST>> { instances };
	}

	O_ENT_ATTR_INST EntityInstance::get_attribute_instance(const std::string& attr_name)
	{
		for (auto& ent_attr_entry : instances)
		{
			if (attr_name == ent_attr_entry.first->get_type_name())
			{
				return std::optional<ENT_ATTR_INST> { ent_attr_entry.second };
			}
		}
		return std::nullopt;
	}


};
};
