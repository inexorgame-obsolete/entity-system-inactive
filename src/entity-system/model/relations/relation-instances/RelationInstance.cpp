// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationInstance.hpp"


namespace inexor {
namespace entity_system {


	RelationInstance::RelationInstance(const REL_TYPE& rel_type, const ENT_INST& ent_inst_source, const ENT_INST& ent_inst_target)
        : GUIDBase(),
		  InstanceBase(rel_type)
	{
		// Store source and target entity instances.
		source_entity_instance = ent_inst_source;
		destination_entity_instance = ent_inst_target;
	}


	RelationInstance::RelationInstance(const xg::Guid& inst_GUID, const REL_TYPE& rel_type, const ENT_INST& ent_inst_source, const ENT_INST& ent_inst_target)
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


	REL_TYPE RelationInstance::get_relation_type() const
	{
		return get_type();
	}


	std::unordered_map<REL_ATTR_TYPE, REL_ATTR_INST> RelationInstance::get_relation_attribute_instances() const
	{
		return relation_attribute_instances;
	}

	
};
};
