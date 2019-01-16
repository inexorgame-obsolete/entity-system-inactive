// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityRelationInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityRelationInstance::EntityRelationInstance(const ENT_REL_TYPE& ent_rel_type, const ENT_INST& ent_type_inst_source, const ENT_INST& ent_type_inst_target)
        : InstanceBase(ent_rel_type)
	{
		// Store the relation type
		// TODO: this->ent_rel_type = ent_rel_type;

		// Store source and target entity type instances.
		source_entity_instance = ent_type_inst_source;
		destination_entity_instance = ent_type_inst_target;
	}


	EntityRelationInstance::~EntityRelationInstance()
	{
		// TODO: Delete all entity relation attribute type instances!
	}


	std::unordered_map<ENT_REL_ATTR_TYPE, ENT_REL_ATTR_INST> EntityRelationInstance::get_relation_attribute_instances() const
	{
		return relation_attribute_instances;
	}

	
};
};
