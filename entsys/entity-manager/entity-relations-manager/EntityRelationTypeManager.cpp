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


	bool EntityRelationTypeManager::does_entity_relation_type_exist(const std::string& param_entity_relation_type_name)
	{
		return does_type_exist(param_entity_relation_type_name);
	}


	std::shared_ptr<EntityRelationType> EntityRelationTypeManager::create_entity_relation_type(const std::string& param_new_entity_relation_type_name,
		                                                                                       const std::shared_ptr<EntityType>& param_source_type,
		                                                                                       const std::shared_ptr<EntityType>& param_destination_type)
	{
		// Validate new entity relation type name.
		if(!is_new_type_name_valid(param_new_entity_relation_type_name)) return entity_relation_type_error;

		// Create new entity relation type.
		std::shared_ptr<EntityRelationType> new_ent_relation_type = std::make_shared<EntityRelationType>(param_new_entity_relation_type_name, param_source_type, param_destination_type);

		// TODO: [CRITICAL] Implement type->get_type_name() method using template classes for types!
		add_type_to_map(param_new_entity_relation_type_name, new_ent_relation_type);
		return new_ent_relation_type;
	}


	const std::size_t EntityRelationTypeManager::get_entity_relation_types_count() const
	{
		return get_type_count();
	}


	ENTSYS_RESULT EntityRelationTypeManager::delete_entity_relation_type(const std::string& param_entity_relation_type_name)
	{
		// TODO: [CRITICAL] Remove all instances of this.
		delete_type(param_entity_relation_type_name);
		return ENTSYS_SUCCESS;
	}

	
	ENTSYS_RESULT EntityRelationTypeManager::delete_entity_relation_type(const std::shared_ptr<EntityRelationType>& param_entity_relation_type)
	{
		return delete_entity_relation_type(param_entity_relation_type->get_type_name());
	}


	void EntityRelationTypeManager::delete_all_entity_relation_types()
	{
		delete_all_types();
	}


};
};
