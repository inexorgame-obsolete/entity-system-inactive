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
		// TODO: implement!
    }

	bool EntityRelationTypeManager::does_entity_relation_type_exist(const std::string& param_entity_relation_type_name)
	{
		// Returns false is entity relation type does not already exist.
		return !(entity_relation_type_map.end() == entity_relation_type_map.find(param_entity_relation_type_name));
	}


	std::shared_ptr<EntityRelationType> EntityRelationTypeManager::create_entity_relation_type(const std::string& param_new_entity_relation_type_name,
		                                                                                       const std::shared_ptr<EntityType>& param_source_type,
		                                                                                       const std::shared_ptr<EntityType>& param_destination_type)
	{
		// TODO: Fix: Check if type does already exist!

		// Create new entity relation type.
		std::shared_ptr<EntityRelationType> new_ent_relation_type = std::make_shared<EntityRelationType>(param_new_entity_relation_type_name, param_source_type, param_destination_type);

		// Add entity relation type.
		entity_relation_type_map[param_new_entity_relation_type_name] = new_ent_relation_type;
		return new_ent_relation_type;
	}


	const std::size_t EntityRelationTypeManager::get_entity_relation_types_count() const
	{
		return entity_relation_type_map.size();
	}


	ENTSYS_RESULT EntityRelationTypeManager::delete_entity_relation_type(const std::string& param_entity_relation_type_name)
	{
		// TODO: [CRITICAL] Remove all instances of this
		// entity relation type before removing the entity relation type itself!
		entity_relation_type_map.erase(param_entity_relation_type_name);
		return ENTSYS_SUCCESS;
	}

	
	ENTSYS_RESULT EntityRelationTypeManager::delete_entity_relation_type(const std::shared_ptr<EntityRelationType>& param_entity_relation_type)
	{
		return delete_entity_relation_type(param_entity_relation_type->get_relation_type_name());
	}


	void EntityRelationTypeManager::delete_all_entity_relation_types()
	{
		entity_relation_type_map.clear();
	}


};
};
