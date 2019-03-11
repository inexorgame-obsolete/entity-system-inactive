#include "RelationInstance.hpp"

namespace inexor {
namespace entity_system {

	RelationInstance::RelationInstance(const RelationTypePtr& rel_type, const EntityInstancePtr& ent_inst_source, const EntityInstancePtr& ent_inst_target)
        : GUIDBase(),
		  InstanceBase(rel_type)
	{
		// Store source and target entity instances.
		source_entity_instance = ent_inst_source;
		destination_entity_instance = ent_inst_target;
	}

	RelationInstance::RelationInstance(const xg::Guid& inst_GUID, const RelationTypePtr& rel_type, const EntityInstancePtr& ent_inst_source, const EntityInstancePtr& ent_inst_target)
		: GUIDBase(inst_GUID),
		  InstanceBase(rel_type)
	{
		// Store source and target entity instances.
		source_entity_instance = ent_inst_source;
		destination_entity_instance = ent_inst_target;
	}

	RelationInstance::~RelationInstance()
	{
		// TODO: Delete all entity relation attribute type instances!
	}

	RelationTypePtr RelationInstance::get_relation_type() const
	{
		return get_type();
	}

	std::unordered_map<RelationAttributeTypePtr, RelationAttributeInstancePtr> RelationInstance::get_relation_attribute_instances() const
	{
		return relation_attribute_instances;
	}

}
}
