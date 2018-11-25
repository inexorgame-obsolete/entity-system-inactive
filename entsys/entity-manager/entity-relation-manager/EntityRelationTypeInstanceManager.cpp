// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    EntityRelationTypeInstanceManager::EntityRelationTypeInstanceManager()
    {
		// TODO: Implement!
    }


    EntityRelationTypeInstanceManager::~EntityRelationTypeInstanceManager()
    {
		// TODO: Implement!
    }


	ENT_REL_TYPE_INST EntityRelationTypeInstanceManager::create_entity_relation_type_instance(
		const ENT_REL_TYPE& ent_rel_type,
		const ENT_TYPE_INST& ent_type_inst_source,
		const ENT_TYPE_INST& ent_type_inst_target)
	
	{
		ENT_REL_TYPE_INST new_relation_type_instance = std::make_shared<EntityRelationTypeInstance>(ent_rel_type, ent_type_inst_source, ent_type_inst_target);

		add_instance_to_buffer(new_relation_type_instance);

		return new_relation_type_instance;
	}


	const std::size_t EntityRelationTypeInstanceManager::get_relation_type_instances_count() const
	{
		return get_type_instance_count();
	}


};
};
