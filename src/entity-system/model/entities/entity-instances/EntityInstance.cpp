#include "EntityInstance.hpp"

namespace inexor {
namespace entity_system {

	EntityInstance::EntityInstance(const EntityTypePtr& ent_type)
		: GUIDBase(),
		InstanceBase(ent_type)
	{
	}

	EntityInstance::EntityInstance(const xg::Guid& ent_inst_GUID, const EntityTypePtr& ent_type)
		: GUIDBase(ent_inst_GUID),
		InstanceBase(ent_type)
	{
	}

	EntityInstance::~EntityInstance()
	{
	}

	EntityTypePtr EntityInstance::get_entity_type() const
	{
		return get_type();
	}

	void EntityInstance::add_entity_attribute_instance(const EntityAttributeTypePtr& ent_attr_type, const EntityAttributeInstancePtr& ent_attr_inst)
	{
		// Use lock guard to ensure thread safety for this write operation!
		std::lock_guard<std::mutex> lock(entity_type_mutex);
		instances[ent_attr_type] = ent_attr_inst;
	}

	std::optional<std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>> EntityInstance::get_instances() const
	{
		if(0 == instances.size())
		{
			return std::nullopt;
		}
		// Read only, no mutex required.
		return std::optional<std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>> { instances };
	}

	EntityAttributeInstancePtrOpt EntityInstance::get_attribute_instance(const std::string& attr_name)
	{
		for(auto& ent_attr_entry : instances)
		{
			if(attr_name == ent_attr_entry.first->get_type_name())
			{
				return EntityAttributeInstancePtrOpt { ent_attr_entry.second };
			}
		}
		return std::nullopt;
	}

}
}
