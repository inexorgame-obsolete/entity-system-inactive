// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    RelationInstanceManager::RelationInstanceManager(
    	std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
    ) : InstanceManagerTemplate()
    {
    	// Store pointer to the entity relation attribute instance manager.
        this->relation_attribute_instance_manager = relation_attribute_instance_manager;
    }


    RelationInstanceManager::~RelationInstanceManager()
    {
		// TODO: Implement!
    }


    O_REL_INST RelationInstanceManager::create_relation_instance(const REL_TYPE& rel_type, const ENT_INST& ent_type_inst_source, const ENT_INST& ent_type_inst_target)
	{
		// Create a new entity relation type instance.
		REL_INST new_relation_instance = std::make_shared<RelationInstance>(rel_type, ent_type_inst_source, ent_type_inst_target);

		// Create all entity relation attribute type instances.
		std::vector<REL_ATTR_TYPE> rel_attributes = rel_type->get_linked_attribute_types();

		// Get the attribute instance map
		std::unordered_map<REL_ATTR_TYPE, REL_ATTR_INST> relation_attribute_instances = new_relation_instance->get_relation_attribute_instances();

		// Create the attribute instances
		for(std::size_t i = 0; i < rel_attributes.size(); i++)
		{
			//relation_attribute_instances[ent_rel_attributes[i]] = this->entity_relation_attribute_instance_manager->create_entity_relation_attribute_instance(ent_rel_attributes[i]);
		}

		// Add the relation type instance to the buffer.
		add_instance(new_relation_instance->get_GUID(), new_relation_instance);

        // Read only, no mutex required.
        return O_REL_INST { new_relation_instance };
	}


	std::size_t RelationInstanceManager::get_relation_instances_count() const
	{
        // Read only, no mutex required.
		return get_instance_count();
	}


	void RelationInstanceManager::delete_all_relation_instances()
	{
		// Call template base class method.
		delete_all_instances();
	}


};
};
