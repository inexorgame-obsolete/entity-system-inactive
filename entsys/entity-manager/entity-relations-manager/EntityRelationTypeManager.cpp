// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationTypeManager.hpp"


namespace inexor {
namespace entity_system {


    EntityRelationTypeManager::EntityRelationTypeManager()
    {
		entity_relation_type_error = std::make_shared<EntityRelationType>("ERROR");
    }


    EntityRelationTypeManager::~EntityRelationTypeManager()
    {
    }


	bool EntityRelationTypeManager::does_entity_relation_type_exist(const std::string& ent_rel_type_name)
	{
		return does_type_exist(ent_rel_type_name);
	}


	std::shared_ptr<EntityRelationType> EntityRelationTypeManager::create_entity_relation_type(const std::string& ent_rel_type_name,
		                                                                                       const std::shared_ptr<EntityType>& ent_type_source,
		                                                                                       const std::shared_ptr<EntityType>& ent_type_target)
	{
		// Validate new entity relation type name.
		if(!is_new_type_name_valid(ent_rel_type_name)) return entity_relation_type_error;

		// Create new entity relation type.
		std::shared_ptr<EntityRelationType> new_ent_relation_type = std::make_shared<EntityRelationType>(ent_rel_type_name, ent_type_source, ent_type_target);

		// Add new entity relation type to type map.
		add_type_to_map(ent_rel_type_name, new_ent_relation_type);
		return new_ent_relation_type;
	}


	const std::size_t EntityRelationTypeManager::get_entity_relation_types_count() const
	{
		return get_type_count();
	}


	ENTSYS_RESULT EntityRelationTypeManager::delete_entity_relation_type(const std::string& ent_rel_type_name)
	{
		delete_type(ent_rel_type_name);
		return ENTSYS_SUCCESS;
	}

	
	ENTSYS_RESULT EntityRelationTypeManager::delete_entity_relation_type(const std::shared_ptr<EntityRelationType>& ent_rel_type)
	{
		return delete_entity_relation_type(ent_rel_type->get_type_name());
	}


	void EntityRelationTypeManager::delete_all_entity_relation_types()
	{
		delete_all_types();
	}


};
};
