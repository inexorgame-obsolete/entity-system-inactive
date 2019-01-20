// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationInstance.hpp"


namespace inexor {
namespace entity_system {


	RelationInstance::RelationInstance(const REL_TYPE& rel_type, const ENT_INST& ent_type_inst_source, const ENT_INST& ent_type_inst_target)
        : InstanceBase(rel_type)
	{
		// Store the relation type
		// TODO: this->rel_type = rel_type;

		// Store source and target entity type instances.
		source_entity_instance = ent_type_inst_source;
		destination_entity_instance = ent_type_inst_target;
	}


	RelationInstance::~RelationInstance()
	{
		// TODO: Delete all entity relation attribute type instances!
	}


	std::unordered_map<REL_ATTR_TYPE, REL_ATTR_INST> RelationInstance::get_relation_attribute_instances() const
	{
		return relation_attribute_instances;
	}

	
};
};
