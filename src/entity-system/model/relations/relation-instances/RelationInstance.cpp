#include "RelationInstance.hpp"

namespace inexor {
namespace entity_system {

	RelationInstance::RelationInstance(const RelationTypePtr& rel_type, const EntityInstancePtr& ent_inst_source, const EntityInstancePtr& ent_inst_target)
		: GUIDBase(),
		InstanceBase(rel_type)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_mutex);
		// Store source entity instances.
		source_entity_instance = ent_inst_source;
		// Store target entity instances.
		destination_entity_instance = ent_inst_target;
	}

	RelationInstance::RelationInstance(const xg::Guid& inst_GUID, const RelationTypePtr& rel_type, const EntityInstancePtr& ent_inst_source, const EntityInstancePtr& ent_inst_target)
		: GUIDBase(inst_GUID),
		InstanceBase(rel_type)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_mutex);
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
		// No mutex required as this is a read-only operation.
		return get_type();
	}

	std::unordered_map<RelationAttributeTypePtr, RelationAttributeInstancePtr> RelationInstance::get_relation_attribute_instances() const
	{
		// No mutex required as this is a read-only operation.
		return relation_attribute_instances;
	}

	EntityInstancePtr RelationInstance::get_source_entity_instance() const
	{
		// No mutex required as this is a read-only operation.
		return source_entity_instance;
	}

	EntityInstancePtr RelationInstance::get_target_entity_instance() const
	{
		// No mutex required as this is a read-only operation.
		return destination_entity_instance;
	}

}
}
