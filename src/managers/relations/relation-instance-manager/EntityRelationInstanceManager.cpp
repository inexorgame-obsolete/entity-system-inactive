// Inexor entity system prototype
// (c)2018-2019 Inexor

#include "EntityRelationInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    EntityRelationInstanceManager::EntityRelationInstanceManager() : InstanceManagerTemplate(entity_relation_type_instance_error)
    {
		// TODO: Implement!
    }


    EntityRelationInstanceManager::~EntityRelationInstanceManager()
    {
		// TODO: Implement!
    }


	ENT_REL_INST EntityRelationInstanceManager::create_entity_relation_type_instance(const ENT_REL_TYPE& ent_rel_type, const ENT_INST& ent_type_inst_source, const ENT_INST& ent_type_inst_target)
	{
		// Create a new entity relation type instance.
		ENT_REL_INST new_relation_type_instance = std::make_shared<EntityRelationInstance>(ent_rel_type, ent_type_inst_source, ent_type_inst_target);

		// Add the relation type instance to the buffer.
		add_instance(new_relation_type_instance->get_GUID(), new_relation_type_instance);

        // Read only, no mutex required.
		return new_relation_type_instance;
	}


	const std::size_t EntityRelationInstanceManager::get_relation_type_instances_count() const
	{
        // Read only, no mutex required.
		return get_instance_count();
	}


};
};
