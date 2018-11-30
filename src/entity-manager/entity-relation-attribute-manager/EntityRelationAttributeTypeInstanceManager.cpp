// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationAttributeTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {

	
	EntityRelationAttributeTypeInstanceManager::EntityRelationAttributeTypeInstanceManager()
	{
		// TODO: Implement!
	}


	EntityRelationAttributeTypeInstanceManager::~EntityRelationAttributeTypeInstanceManager()
	{
		// TODO: Implement!
	}


	ENT_REL_ATTR_TYPE_INST EntityRelationAttributeTypeInstanceManager
		::create_entity_relation_attribute_type_instance(const ENT_REL_ATTR_TYPE& ent_rel_attr_type)
	{
		// Create a new entity relation attribute type instance.
		ENT_REL_ATTR_TYPE_INST new_ent_rel_attr_type_inst
			= std::make_shared<EntityRelationAttributeTypeInstance>(ent_rel_attr_type);
		
		// Call base template class method.
		add_instance_to_buffer(new_ent_rel_attr_type_inst);

		return new_ent_rel_attr_type_inst;
	}


	const std::size_t EntityRelationAttributeTypeInstanceManager::get_entity_relation_attribute_type_instance_count() const
	{
		return get_type_instance_count();
	}

	
	void EntityRelationAttributeTypeInstanceManager::delete_all_entity_relation_type_attribute_instances()
	{
		return delete_all_type_instances();
	}


};
};
