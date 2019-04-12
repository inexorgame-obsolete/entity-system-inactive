#include "RelationInstance.hpp"

namespace inexor {
namespace entity_system {

	RelationInstance::RelationInstance(const RelationTypePtr& rel_type, const EntityInstancePtr& ent_inst_source, const EntityInstancePtr& ent_inst_target)
		: GUIDBase(),
		InstanceBase(rel_type)
	{
		// Store source entity instances.
		source_entity_instance = ent_inst_source;
		// Store target entity instances.
		destination_entity_instance = ent_inst_target;
	}

	RelationInstance::RelationInstance(const xg::Guid& inst_GUID, const RelationTypePtr& rel_type, const EntityInstancePtr& ent_inst_source, const EntityInstancePtr& ent_inst_target)
		: GUIDBase(inst_GUID),
		InstanceBase(rel_type)
	{
		// Store source entity instances.
		source_entity_instance = ent_inst_source;
		// Store target entity instances.
		destination_entity_instance = ent_inst_target;
	}

	RelationInstance::~RelationInstance()
	{
	}

	RelationTypePtr RelationInstance::get_relation_type() const
	{
		return get_type();
	}

	std::unordered_map<RelationAttributeTypePtr, RelationAttributeInstancePtr> RelationInstance::get_relation_attribute_instances() const
	{
		return relation_attribute_instances;
	}

	EntityInstancePtr RelationInstance::get_source_entity_instance() const
	{
		return source_entity_instance;
	}

	EntityInstancePtr RelationInstance::get_target_entity_instance() const
	{
		return destination_entity_instance;
	}

}
}
