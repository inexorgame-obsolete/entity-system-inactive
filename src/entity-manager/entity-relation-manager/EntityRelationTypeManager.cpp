// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationTypeManager.hpp"


namespace inexor {
namespace entity_system {


    EntityRelationTypeManager::EntityRelationTypeManager()
    {
		// TODO: Implement!
    }


    EntityRelationTypeManager::~EntityRelationTypeManager()
    {
		// TODO: Implement!
    }


	bool EntityRelationTypeManager::does_entity_relation_type_exist(const std::string& ent_rel_type_name)
	{
		return does_type_exist(ent_rel_type_name);
	}


	bool EntityRelationTypeManager::does_entity_relation_type_exist(const ENT_REL_TYPE& ent_rel_type)
	{
		return does_entity_relation_type_exist(ent_rel_type->get_type_name());
	}


	ENT_REL_TYPE EntityRelationTypeManager::create_entity_relation_type(const std::string& ent_rel_type_name,
                                                                        const ENT_TYPE& ent_type_source,
                                                                        const ENT_TYPE& ent_type_target)
	{
		// Validate new entity relation type name.
		if(!is_type_name_valid(ent_rel_type_name))
		{
			// This entity relation type does already exist.
			// TODO: Throw error message.
			return entity_relation_type_error;
		}

		// Create new entity relation type.
		ENT_REL_TYPE new_ent_relation_type
			= std::make_shared<EntityRelationType>(ent_rel_type_name,
				                                   ent_type_source,
				                                   ent_type_target);

		// Add new entity relation type to type map.
		add_type(ent_rel_type_name, new_ent_relation_type);

		return new_ent_relation_type;
	}


	const std::size_t EntityRelationTypeManager::get_entity_relation_types_count() const
	{
		return get_type_count();
	}


	void EntityRelationTypeManager::delete_entity_relation_type(const std::string& ent_rel_type_name)
	{
		delete_type(ent_rel_type_name);
	}

	
	void EntityRelationTypeManager::delete_entity_relation_type(const ENT_REL_TYPE& ent_rel_type)
	{
		return delete_entity_relation_type(ent_rel_type->get_type_name());
	}


	void EntityRelationTypeManager::delete_all_entity_relation_types()
	{
		delete_all_types();
	}


};
};
