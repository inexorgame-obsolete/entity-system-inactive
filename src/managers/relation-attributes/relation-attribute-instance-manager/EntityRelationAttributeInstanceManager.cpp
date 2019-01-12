// Inexor entity system prototype
// (c)2018-2019 Inexor

#include "EntityRelationAttributeInstanceManager.hpp"


namespace inexor {
namespace entity_system {

	
	EntityRelationAttributeInstanceManager::EntityRelationAttributeInstanceManager() : InstanceManagerTemplate(entity_relation_attribute_type_instance_error)
	{
		// TODO: Implement!
	}


	EntityRelationAttributeInstanceManager::~EntityRelationAttributeInstanceManager()
	{
		// TODO: Implement!
	}


	ENT_REL_ATTR_INST EntityRelationAttributeInstanceManager::create_entity_relation_attribute_type_instance(const ENT_REL_ATTR_TYPE& ent_rel_attr_type)
	{
		// Create a new entity relation attribute type instance.
		ENT_REL_ATTR_INST new_ent_rel_attr_inst = std::make_shared<EntityRelationAttributeInstance>(ent_rel_attr_type);
		
		// Call base template class method.
		add_instance(new_ent_rel_attr_inst->get_GUID(), new_ent_rel_attr_inst);

        // Read only, no mutex required.
		return new_ent_rel_attr_inst;
	}


	const std::size_t EntityRelationAttributeInstanceManager::get_entity_relation_attribute_type_instance_count() const
	{
		return get_instance_count();
	}

	
	void EntityRelationAttributeInstanceManager::delete_all_entity_relation_type_attribute_instances()
	{
		return delete_all_instances();
	}


};
};
