// Inexor entity system prototype
// (c)2018-2019 Inexor

#include "EntityRelationInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {

	
	extern std::shared_ptr<EntitySystem> entsys;


	EntityRelationInstance::EntityRelationInstance(const ENT_REL_TYPE& ent_rel_type, const ENT_INST& ent_type_inst_source, const ENT_INST& ent_type_inst_target) : InstanceBase(ent_rel_type)
	{
		// Store source and target entity type instances.
		source_entity_type_instance = ent_type_inst_source;
		destination_entity_type_instance = ent_type_inst_target;

		// Create all entity relation attribute type instances.
		std::vector<ENT_REL_ATTR_TYPE> ent_rel_attributes = ent_rel_type->get_linked_attribute_types();

		for(std::size_t i=0; i<ent_rel_attributes.size(); i++)
		{
			relation_attribute_instances[ent_rel_attributes[i]] = entsys->create_entity_relation_attribute_type_instance(ent_rel_attributes[i]);
		}
	}


	EntityRelationInstance::~EntityRelationInstance()
	{
		// TODO: Delete all entity relation attribute type instances!
	}

	
};
};
