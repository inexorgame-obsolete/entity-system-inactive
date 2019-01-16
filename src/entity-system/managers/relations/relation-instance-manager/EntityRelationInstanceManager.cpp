// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityRelationInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    EntityRelationInstanceManager::EntityRelationInstanceManager() : InstanceManagerTemplate()
    {
    	// Store pointer to the entity relation attribute instance manager.
        this->entity_relation_attribute_instance_manager = entity_relation_attribute_instance_manager;
    }


    EntityRelationInstanceManager::~EntityRelationInstanceManager()
    {
		// TODO: Implement!
    }


	std::optional<ENT_REL_INST> EntityRelationInstanceManager::create_entity_relation_instance(const ENT_REL_TYPE& ent_rel_type, const ENT_INST& ent_type_inst_source, const ENT_INST& ent_type_inst_target)
	{
		// Create a new entity relation type instance.
		ENT_REL_INST new_relation_instance = std::make_shared<EntityRelationInstance>(ent_rel_type, ent_type_inst_source, ent_type_inst_target);

		// Create all entity relation attribute type instances.
		std::vector<ENT_REL_ATTR_TYPE> ent_rel_attributes = ent_rel_type->get_linked_attribute_types();

		// Get the attribute instance map
		std::unordered_map<ENT_REL_ATTR_TYPE, ENT_REL_ATTR_INST> relation_attribute_instances = new_relation_instance->get_relation_attribute_instances();

		// Create the attribute instances
		for(std::size_t i = 0; i < ent_rel_attributes.size(); i++)
		{
			//relation_attribute_instances[ent_rel_attributes[i]] = this->entity_relation_attribute_instance_manager->create_entity_relation_attribute_instance(ent_rel_attributes[i]);
		}

		// Add the relation type instance to the buffer.
		add_instance(new_relation_instance->get_GUID(), new_relation_instance);

        // Read only, no mutex required.
        return std::optional<ENT_REL_INST> { new_relation_instance };
	}


	std::size_t EntityRelationInstanceManager::get_relation_instances_count() const
	{
        // Read only, no mutex required.
		return get_instance_count();
	}


};
};
