// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    EntityRelationTypeInstanceManager::EntityRelationTypeInstanceManager()
    {
		// TODO: implement!
    }


    EntityRelationTypeInstanceManager::~EntityRelationTypeInstanceManager()
    {
		// TODO: implement!
    }


	std::shared_ptr<EntityRelationTypeInstance> EntityRelationTypeInstanceManager::create_entity_relation_type_instance(
		const std::shared_ptr<EntityRelationType>& ent_relation_type,
		const std::shared_ptr<EntityTypeInstance>& ent_type_instance_source,
		const std::shared_ptr<EntityTypeInstance>& ent_type_instance_destination)
	
	{
		std::shared_ptr<EntityRelationTypeInstance> new_relation_type_instance
			= std::make_shared<EntityRelationTypeInstance>(ent_relation_type,
			                                               ent_type_instance_source,
				                                           ent_type_instance_destination);

		add_instance_to_buffer(new_relation_type_instance);

		return new_relation_type_instance;
	}


	const std::size_t EntityRelationTypeInstanceManager::get_relation_type_instances_count() const
	{
		return get_type_instance_count();
	}

};
};
