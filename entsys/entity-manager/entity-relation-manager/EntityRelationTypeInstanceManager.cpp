// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    EntityRelationTypeInstanceManager::EntityRelationTypeInstanceManager()
    {
    }


    EntityRelationTypeInstanceManager::~EntityRelationTypeInstanceManager()
    {
    }


	std::shared_ptr<EntityRelationTypeInstance> EntityRelationTypeInstanceManager::create_entity_relation_type_instance(
		const std::shared_ptr<EntityRelationType>& ent_rel_type,
		const std::shared_ptr<EntityTypeInstance>& ent_type_inst_source,
		const std::shared_ptr<EntityTypeInstance>& ent_type_inst_target)
	
	{
		std::shared_ptr<EntityRelationTypeInstance> new_relation_type_instance
			= std::make_shared<EntityRelationTypeInstance>(ent_rel_type, ent_type_inst_source, ent_type_inst_target);

		add_instance_to_buffer(new_relation_type_instance);

		return new_relation_type_instance;
	}


	const std::size_t EntityRelationTypeInstanceManager::get_relation_type_instances_count() const
	{
		return get_type_instance_count();
	}


};
};
